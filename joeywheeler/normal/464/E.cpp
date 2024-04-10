#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define NMOD 3

using namespace std;

typedef long long ll;

ll mod[NMOD] = {1000000009,1000000007,1000000003};
ll pw[200005][NMOD];

bool overflow = false;

typedef struct _rt {
    _rt *l, *r;
    int hash[NMOD];
    bool all1;

    _rt() {
        l = 0, r = 0, all1 = false;
        FO(i,0,NMOD) hash[i] = 0;
    }

    void good() {
        assert(hash[0] == hash[1]);
    }

    _rt *add(int sz, int i) {
        // this is sz bits, add 2^i
        _rt *ret = new _rt;
        memcpy(ret, this, sizeof(_rt));
        if (sz == 1) {
            if (all1) {
                overflow = true;
                ret->all1 = false;
                FO(j,0,NMOD) ret->hash[j] = 0;
            } else {
                overflow = false;
                ret->all1 = true;
                FO(j,0,NMOD) ret->hash[j] = 1;
            }
            return ret;
        }
        if (l == NULL) ret->l = l = new _rt;
        if (r == NULL) ret->r = r = new _rt;
        if (i == 0 && all1) {
            ret->l = NULL; ret->r = NULL; ret->all1 = false;
            FO(j,0,NMOD) ret->hash[j] = 0;
            overflow = true;
            return ret;
        } else {
            int lsz = sz/2;
            int rsz = sz-lsz;
            if (i < rsz) {
                ret->r = r->add(rsz, i);
                if (overflow) {
                    ret->l = l->add(lsz,0);
                    // overflow = overflow;
                } else {
                    overflow = false;
                }
            } else {
                i -= rsz;
                ret->l = l->add(lsz, i);
                // overflow = overflow
            }
            ret->all1 = ret->l->all1 && ret->r->all1;
            FO(j,0,NMOD) ret->hash[j] = (ret->r->hash[j] + pw[rsz][j] * ret->l->hash[j]) % mod[j];
            return ret;
        }
    }
} *rt;

#define safeget(a,x,y) (a?a->x:y)

bool lesscmp(rt a, rt b, int sz) {
    if (b == NULL) return false;

    if (sz == 1) return safeget(a,hash[0],0) < safeget(b,hash[0],0);
    else {
        int lsz = sz/2;
        int rsz = sz-lsz;
        bool eq = true;
        FO(j,0,NMOD) {
            eq &= safeget(safeget(a,l,NULL),hash[j],0) == safeget(safeget(b,l,NULL),hash[j],0);
        }
        if (!eq) return lesscmp(safeget(a,l,NULL), safeget(b,l,NULL), lsz);
        else return lesscmp(safeget(a,r,NULL), safeget(b,r,NULL), rsz);
    }
}

#define INF ((rt)0xf032df02)

class CMP {
    public:;
    bool operator()(const pair<rt,int> &_a, const pair<rt,int> &_b) const {
        rt a = _a.first, b = _b.first;
        swap(a,b);
        if (a == INF) return false;
        if (b == INF) return true;
        return lesscmp(a, b, 200002);
    }
};

typedef pair<int,int> ii;

int n, m;
vector<ii> adj[200005];
rt dist[200005];
bool proc[200005];
int prev[200005];

priority_queue<pair<rt,int>, vector<pair<rt,int> >, CMP> q;

int main() {
    FO(i,0,NMOD) pw[0][i] = 1;
    FO(i,1,200005) FO(j,0,NMOD) pw[i][j] = (pw[i-1][j] * 2ll) % mod[j];

    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        u--; v--;
        adj[u].push_back(ii(v,x));
        adj[v].push_back(ii(u,x));
    }
    FO(i,0,n) dist[i] = INF;

    int s, t; scanf("%d %d", &s, &t); s--; t--;
    dist[s] = new _rt;
    q.push(make_pair(dist[s],s));
    while (!q.empty()) {
        int f = q.top().second; q.pop();
        if (proc[f]) continue;
        proc[f] = true;

        FO(i,0,sz(adj[f])) {
            int ni = adj[f][i].first;
            if (!proc[ni]) {
                rt nd = dist[f]->add(200002, adj[f][i].second);
                if (dist[ni] == INF || lesscmp(nd, dist[ni],200002)) {
                    prev[ni] = f;
                    dist[ni] = nd;
                    q.push(make_pair(dist[ni],ni));
                }
            }
        }
    }

    if (dist[t] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[t]->hash[1]);
        vector<int> p; p.push_back(t);
        while (t != s) {
            t = prev[t];
            p.push_back(t);
        }
        printf("%d\n", sz(p));
        for (int i = sz(p)-1; i >= 0; i--) printf("%d ", p[i]+1);
        printf("\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define sz(v) int(v.size())

int n, m, s, t;
vector<pair<int,int> > u[400005];
vector<tuple<int,int,int> > el;
vector<pair<int,int> > aux[400005];
bool hasST;

vector<int> chk[400005];

bool sn[1000005];
int dp[1000005];
int nxt[1000005];
int cc[1000005];
int ed[1000005];
int detp[1000005];
int par[1000005];
int parei[1000005];
int outd[1000005];
int ind[1000005];

priority_queue<tuple<int,int,int> > toProc;

// w = 0 down, w = 1 up
void setdir(int i, int j, int ei, int w) {
    //assert(dp[i] < dp[j]);
    //assert(ed[ei] == -1);

    //printf("SET DIR %d%s%d %d %d\n", i, w==0 ? "->" : "<-", j, ei, w);
    ed[ei] = w;

    toProc.emplace(-dp[j],!w,j);

    if (dp[j] == dp[i]+1) {
        detp[j] = w;
        for (auto e : aux[j]) {
            int nj, nei; tie(nj, nei) = e;
            //assert(dp[i] < dp[nj]);
            setdir(i, nj, nei, w);
        }
    }
}

bool go1(int i, int pr, int dep) {
    sn[i] = true;
    dp[i] = dep;
    //if (i == 0) printf("dp[%d]=%d\n", i, dp[i]);
    par[i] = pr;
    bool retVal = false;
    for (auto e : u[i]) {
        int j, ei; tie(j, ei) = e;
        if (j != pr) {
            if (!sn[j]) {
                cc[i] = j;
                parei[j] = ei;

                //printf("%d->%d\n", i, j);
                if (go1(j, i, dep+1)) {
                    retVal = true;
                }
            } else {
                if (dp[j] < dp[i]) {
                    // going up
                    //printf("AUX UP: %d ^ %d\n", i, j);
                    nxt[ei] = cc[j];
                    //printf("nxt is %d\n", nxt[ei]);
                    aux[cc[j]].emplace_back(i,ei);
                } else {
                    // going down
                    //printf("AUX DOWN: %d v %d\n", i, j);
                }
            }
        }
    }
    retVal |= i == t;
    return retVal;
}

bool go2(int i, int pr, int dep) {
    //printf("i=%d\n", i);
    //printf("%d, %d\n", dp[i], dep);
    //assert(dp[i] == dep);
    sn[i] = true;
    bool retVal = false;
    for (auto e : u[i]) {
        int j, ei; tie(j, ei) = e;
        if (j != pr) {
            if (!sn[j]) {
                if (go2(j, i, dep+1)) {
                    retVal = true;
                    //assert(dp[i] < dp[j]);
                    setdir(i, j, ei, 0);
                }
            }
        }
    }
    retVal |= i == t;
    return retVal;
}

int main() {
    memset(detp, -1, sizeof detp);
    memset(ed, -1, sizeof ed);

    int T; scanf("%d", &T);
    FO(Z,0,T) {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        s--; t--;

        FO(i,0,m) {
            int x, y; scanf("%d %d", &x, &y); x--; y--;
            if (x > y) swap(x,y);
            el.emplace_back(x,y,i);

            u[x].emplace_back(y,i);
            u[y].emplace_back(x,i);

            if ((x == s && y == t) || (x == t && y == s)) {
                hasST = true;
            }
        }
        if (!hasST) {
            int x = s, y = t;

            if (x > y) swap(x,y);
            el.emplace_back(x,y,m);

            u[x].emplace_back(y,m);
            u[y].emplace_back(x,m);
        }
        go1(s,-1,0);
        FO(i,0,n) sn[i] = false;
        go2(s,-1,0);

        while (sz(toProc)) {
            auto f = toProc.top(); toProc.pop();
            int _dpth, w, i; tie(_dpth, w, i) = f;

            //printf("w=%d, i=%d\n", w, i);

            while (detp[i] == -1) {
                setdir(par[i], i, parei[i], w);
                i = par[i];
            }
        }

        queue<int> q;
        FO(i,0,sz(el)) {
            int x, y, ei;
            tie(x,y,ei) = el[i];
            if (ed[ei] == -1) {
                printf("No\n");
                goto end;
            }
            if ((ed[ei] == 1) ^ (dp[x] < dp[y])) {
                //printf("%d=>%d\n", x, y);
                chk[x].push_back(y);
                outd[x]++;
                ind[y]++;
            } else {
                //printf("%d=>%d\n", y, x);
                chk[y].push_back(x);
                outd[y]++;
                ind[x]++;
            }
        }

        FO(i,0,n) {
            if ((i == s && ind[i] != 0) || 
                (i == t && outd[i] != 0) ||
                (i != s && i != t &&
                    (ind[i] == 0 || outd[i] == 0))) {
                printf("No\n");
                goto end;
            }
        }
        FO(i,0,n) sn[i] = false;

        q.push(s);
        while (sz(q)) {
            int i = q.front(); q.pop();
            sn[i] = true;
            for (int j : chk[i]) {
                ind[j]--;
                if (ind[j] == 0) {
                    q.push(j);
                }
            }
        }

        FO(i,0,n) {
            if (!sn[i]) {
                printf("No\n");
                goto end;
            }
        }

        printf("Yes\n");
        FO(i,0,m) {
            int x, y, ei;
            tie(x,y,ei) = el[i];
            if ((ed[ei] == 1) ^ (dp[x] < dp[y])) {
                printf("%d %d\n", x+1, y+1);
            } else {
                printf("%d %d\n", y+1, x+1);
            }
        }

        end:;

        // TODO: CLEAR DS
        el.clear();
        hasST = false;
        FO(i,0,n) {
            u[i].clear();
            aux[i].clear();
            sn[i] = false;
            dp[i] = 0;
            nxt[i] = 0;
            cc[i] = 0;
            par[i] = 0;
            parei[i] = 0;
            ind[i] = 0;
            outd[i] = 0;
            detp[i] = -1;
            chk[i].clear();
        }
        FO(i,0,m+1) {
            ed[i] = -1;
        }
        n = m = s = t = 0;

        /*
         *int n, m, s, t;
vector<pair<int,int> > u[400005];
vector<tuple<int,int,int> > el;
vector<pair<int,int> > aux[400005];
bool hasST;

vector<int> chk[400005];

bool sn[400005];
int dp[400005];
int nxt[400005];
int cc[400005];
int ed[1000005];
int detp[400005];
int par[400005];
int parei[400005];
int outd[400005];
int ind[400005];
*/

    }
    return 0;
}
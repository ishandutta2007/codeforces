#include <bits/stdc++.h>
using namespace std;

#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;
const int N = 211111;
const int K = 20;
const int INF = 1<<30;

int n;
int parent[N], depth[N], anc[K][N];
vector<int> adj[N];
int ascend(int i, int d) {
    fr(k,K) {
        if (d & 1) i = anc[k][i];
        d >>= 1;
    }
    return i;
}
int lca(int i, int j) {
    if (depth[i] > depth[j]) i = ascend(i, depth[i] - depth[j]);
    if (depth[j] > depth[i]) j = ascend(j, depth[j] - depth[i]);
    if (i == j) return i;
    ffr(k,K) {
        if (anc[k][i] != anc[k][j]) {
            i = anc[k][i];
            j = anc[k][j];
        }
    }
    return parent[i];
}

int rparent[N], ranc[K][N];
void add_route(int i, int a) {
    if (depth[rparent[i]] > depth[a]) rparent[i] = a;
}
void compute_climbs() {
    ffo(i,1,n) {
        if (depth[rparent[parent[i]]] > depth[rparent[i]]) {
            rparent[parent[i]] = rparent[i];
        }
    }
    fr(i,n) ranc[0][i] = rparent[i];
    fr(k,K-1) {
        fr(i,n) ranc[k + 1][i] = ranc[k][ranc[k][i]];
    }
}

int dist(int i, int a) {
    if (i == a) return 0;
    if (depth[ranc[K-1][i]] > depth[a]) return INF;
    int d = 1;
    ffr(k,K) {
        if (depth[ranc[k][i]] > depth[a]) {
            i = ranc[k][i];
            d += 1 << k;
        }
    }
    return d;
}

int go(int i, int d) {
    fr(k,K) {
        if (d & 1) i = ranc[k][i];
        d >>= 1;
    }
    return i;
}

int countv(vector<int>& vs, int v) {// how many are <= vs
    int L = -1, R = vs.size(); // vs[L] < v <= vs[R]
    while (R - L > 1) {
        int M = L + R >> 1;
        (vs[M] <= v ? L : R) = M;
    }
    return R;
}

vector<pair<int,int>> covers;
void add_cover(int a, int b) {
    covers.emplace_back(a, b);
    covers.emplace_back(b, a);
}
int prel[N], prer[N];
struct Seg {
    int xi, xj;
    vector<int> ys;
    Seg *l, *r;
    Seg(int i, int j): xi(covers[i].first), xj(covers[j].first) {
        if (i == j) {
            l = r = NULL;
            ys.push_back(covers[i].second);
        } else {
            int k = i + j >> 1;
            l = new Seg(i, k);
            r = new Seg(k + 1, j);
            for (int li = 0, ri = 0; li < l->ys.size() || ri < r->ys.size();) {
                ys.push_back(
                    li < l->ys.size() && (ri >= r->ys.size() || l->ys[li] < r->ys[ri]) ?
                    l->ys[li++] : r->ys[ri++]);
            }
        }
    }
    bool has(int XI, int XJ, int YI, int YJ) {
        if (XI <= xi && xj <= XJ) {
            return countv(ys, YJ) != countv(ys, YI - 1);
        } else if (!(XJ < xi || xj < XI) && l) {
            if (l->has(XI, XJ, YI, YJ)) return true;
            if (r->has(XI, XJ, YI, YJ)) return true;
        }
        return false;
    }
};

Seg *seg;

void compute_covers() {
    vector<int> pre;
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int i = st.top(); st.pop();
        pre.push_back(i);
        for (int j : adj[i]) st.push(j);
    }
    fr(f,n) prel[pre[f]] = prer[pre[f]] = f;
    ffr(f,n) {
        int i = pre[f];
        if (f) {
            int p = parent[i];
            prer[p] = max(prer[p], prer[i]);
        }
    }
    for (int i = 0; i < covers.size(); i++) {
        covers[i].first = prel[covers[i].first];
        covers[i].second = prel[covers[i].second];
    }
    sort(covers.begin(), covers.end());
    seg = new Seg(0, covers.size() - 1);
}
bool covered(int a, int b) {
    return seg->has(prel[a], prer[a], prel[b], prer[b]);
}





int main() {
    sf("%d", &n);
    fr(i,n) {
        rparent[i] = i;
    }
    fo(i,1,n) {
        sf("%d", &parent[i]);
        adj[--parent[i]].push_back(i);
        depth[i] = depth[parent[i]] + 1;
    }
    fr(i,n) anc[0][i] = parent[i];
    fr(k,K-1) {
        fr(i,n) anc[k + 1][i] = anc[k][anc[k][i]];
    }
    int r;
    sf("%d", &r);
    fr(i,r) {
        int a, b;
        sf("%d%d", &a, &b);
        a--, b--;
        int l = lca(a, b);
        add_route(a, l);
        add_route(b, l);
        add_cover(a, b);
    }
    compute_climbs();
    compute_covers();

    int q;
    sf("%d", &q);
    while (q--) {
        int u, v;
        sf("%d%d", &u, &v);
        u--, v--;
        int l = lca(u, v);
        int du = dist(u, l);
        int dv = dist(v, l);
        if (du >= INF || dv >= INF) {
            pf("-1\n");
        } else {
            int ans = du + dv;
            if (du && dv && covered(go(u, du - 1), go(v, dv - 1))) ans--;
            pf("%d\n", ans);
        }
    }
}
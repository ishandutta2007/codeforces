#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct clrarr {
    int a[100005];
    int t[100005];
    int T;
    int def;

    clrarr(int defval = 0) {
        def = defval;
        T = 1;
    }

    void clear() {
        T++;
    }

    int &gv(int i) {
        if (t[i] != T) {
            t[i] = T;
            a[i] = def;
        }
        return a[i];
    }
} sp(0), dp[2] = {clrarr(10000000), clrarr(10000000)};

vector<int> u[100005];
int n;
int o[100005], O;
int p[18][100005];
int d[100005];

void go(int i, int p) {
    o[i] = ++O;
    ::p[0][o[i]] = o[p];
    d[o[i]] = d[o[p]]+1;
    for (int j : u[i]) if (j != p) {
        go(j, i);
    }
}

int lca(int i, int j) {
    if (d[i] < d[j]) swap(i,j);
    for (int k = 17; k >= 0; k--) if (d[i]-(1<<k) >= d[j]) i = p[k][i];
    if (i == j) return i;
    for (int k = 17; k >= 0; k--) if (p[k][i] != p[k][j]) {
        i = p[k][i];
        j = p[k][j];
    }
    return p[0][i];
}

set<int> adj[100005];

int f(int canexp, int i) {
    int &res = dp[canexp].gv(i);
    if (res <= 1e6) return res;
    res = 1.5e5;
    if (sp.gv(i)) {
        if (!canexp) return res;
        // can't expose any children
        int tr = 0;
        for (int j : adj[i]) tr += f(0, j);
        res = min(res, tr);
    } else {
        // delete this vertex ?, expose all
        int tr = 1;
        for (int j : adj[i]) tr += f(1, j);
        res = min(res, tr);
        // don't delete this
        if (!canexp) {
            // can't expose any children
            tr = 0;
            for (int j : adj[i]) tr += f(0, j);
            res = min(res, tr);
        } else {
            //if (canexp == 1 && i == 1) printf("??\n");
            // expose one
            tr = 0;
            int mndf = 0;
            for (int j : adj[i]) {
                tr += f(0, j);
                mndf = min(mndf, f(1,j)-f(0,j));
            }
            res = min(res, tr+mndf);
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    FO(i,1,18) FO(j,1,n+1) p[i][j] = p[i-1][p[i-1][j]];
    int q; scanf("%d", &q);
    FO(z,0,q) {
        int k; scanf("%d", &k);
        sp.clear();
        vector<int> v;
        FO(i,0,k) {
            int x; scanf("%d", &x); x = o[x];
            sp.gv(x) = 1;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        vector<int> vv;
        FO(i,0,sz(v)) {
            vv.push_back(v[i]);
            if (p[0][v[i]]) vv.push_back(p[0][v[i]]);
        }
        v = vv;
        sort(v.begin(),v.end());
        FO(i,0,sz(v)-1) {
            vv.push_back(lca(v[i],v[i+1]));
        }
        v = vv;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        FO(i,1,sz(v)) {
            int pr = lca(v[i],v[i-1]);
            //printf("p[%d]=%d\n", v[i], pr);
            adj[pr].insert(v[i]);
        }
        //for (int x : v) printf("%d ", x);
        //printf("\n");
        dp[0].clear();
        dp[1].clear();
        int res = f(1,v[0]);
        if (res >= 1.1e5) res = -1;
        printf("%d\n", res);
        //printf("%d\n", f(1,2));
        //printf("%d\n", f(0,5));

        for (int x : v) adj[x].clear();
    }
}
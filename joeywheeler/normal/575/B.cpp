#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<int> u[100005];
int d[100005];
int a[100005], b[100005], x[100005];
int p[18][100005];

int up[100005], down[100005];

void go(int i, int pr) {
    p[0][i] = pr;
    d[i] = d[pr]+1;
    for (int j : u[i]) if (j != pr) {
        go(j, i);
    }
}

void go2(int i, int pr) {
    for (int j : u[i]) if (j != pr) {
        go2(j, i);
        up[i] += up[j];
        down[i] += down[j];
    }
}
int lca(int a, int b) {
    if (d[a] < d[b]) swap(a,b);
    for (int i = 17; i >= 0; i--) if (d[p[i][a]] >= d[b]) a = p[i][a];
    if (a == b) return a;
    for (int i = 17; i >= 0; i--) if (p[i][a] != p[i][b]) {
        a = p[i][a];
        b = p[i][b];
    }
    return p[0][a];
}

typedef long long ll;
#define MOD 1000000007ll

ll cof[1000005];
ll pw[1000005];

int main() {
    scanf("%d", &n);
    pw[0] = 1;
    FO(i,1,1000005) {
        pw[i] = (pw[i-1]*2)%MOD;
        cof[i] = cof[i-1]+pw[i-1];
        if (cof[i] >= MOD) cof[i] -= MOD;
    }
    FO(i,0,n-1) {
        int l,m,y; scanf("%d%d%d", &l, &m, &y);
        u[l].push_back(m);
        u[m].push_back(l);
        a[i] = l; b[i] = m; x[i] = y;
    }
    go(1,0);
    FO(i,1,18) FO(j,1,n+1) p[i][j] = p[i-1][p[i-1][j]];
    int pos = 1;
    int k; scanf("%d", &k);
    FO(z,0,k) {
        int nxt; scanf("%d", &nxt);
        int l = lca(pos,nxt);
        up[pos]++;
        up[l]--;
        down[nxt]++;
        down[l]--;
        pos = nxt;
    }
    go2(1,0);
    ll res = 0;
    FO(i,0,n-1) if (x[i]) {
        if (d[a[i]] < d[b[i]]) {
            // count up
            int r = up[b[i]];
            res += cof[r];
        } else {
            // count down
            int r = down[a[i]];
            res += cof[r];
        }
    }
    res %= MOD;
    printf("%lld\n", res % MOD);
}
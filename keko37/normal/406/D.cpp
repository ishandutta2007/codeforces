#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const int LOG = 19;

llint n, m;
llint x[MAXN], y[MAXN];
int par[MAXN] [LOG], dub[MAXN];

int calc (int a, int b, int c) {
    if (c == 0) return b;
    if ((y[b] - y[a]) * (x[c] - x[b]) >= (y[c] - y[b]) * (x[b] - x[a])) {
        return b;
    } else {
        return calc(a, c, par[c] [0]);
    }
}

int kth (int a, int k) {
    int pot = 0;
    while (k) {
        if (k & 1) a = par[a] [pot];
        pot++;
        k/=2;
    }
    return a;
}

int lca (int a, int b) {
    if (dub[a] < dub[b]) swap(a, b);
    a = kth(a, dub[a] - dub[b]);
    if (a == b) return a;
    for (int i=LOG-1; i>=0; i--) {
        if (par[a] [i] != par[b] [i]) {
            a = par[a] [i];
            b = par[b] [i];
        }
    }
    return par[a] [0];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=n-1; i>=1; i--) {
        par[i] [0] = calc(i, i+1, par[i+1] [0]);
        dub[i] = 1 + dub[par[i] [0]];
    }
    for (int i=1; i<LOG; i++) {
        for (int j=1; j<=n; j++) {
            par[j] [i] = par[par[j] [i-1]] [i-1];
        }
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << " ";
    }
    return 0;
}
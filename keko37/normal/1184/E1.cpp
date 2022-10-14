#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MAXM = 1000005;

int n, m;
int a[MAXM], b[MAXM], w[MAXM];
pair <int, int> p[MAXM];
int par[MAXN];

int nadi (int x) {
    if (par[x] == x) return x;
    return par[x] = nadi(par[x]);
}

bool spoji (int x, int y) {
    x = nadi(x); y = nadi(y);
    if (x == y) return 0;
    par[y] = x;
    return 1;
}

bool mst (int e, int val) {
    for (int i=1; i<=n; i++) {
        par[i] = i;
    }
    for (int i=1; i<=m; i++) {
        if (i == e) {
            p[i] = make_pair(val, -i);
        } else {
            p[i] = make_pair(w[i], i);
        }
    }
    sort(p+1, p+1+m);
    for (int i=1; i<=m; i++) {
        int ind = p[i].second;
        if (ind > 0) {
            spoji(a[ind], b[ind]);
        } else {
            return spoji(a[e], b[e]);
        }
    }
}

int bs (int e) {
    int lo = 0, hi = 1000000000;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (mst(e, mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> a[i] >> b[i] >> w[i];
    }
    cout << bs(1);
    return 0;
}
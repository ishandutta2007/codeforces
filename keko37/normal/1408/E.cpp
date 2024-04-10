#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint m, n, sol;
llint a[MAXN], b[MAXN];
int par[MAXN];
vector < pair <int, pi> > v;

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

bool spoji (int a, int b) {
    a = nadi(a); b = nadi(b);
    if (a == b) return 0;
    par[a] = b;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n + m; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        int br; cin >> br;
        for (int j = 0; j < br; j++) {
            int x; cin >> x;
            v.push_back({a[i] + b[x], {x, n + i}});
            sol += a[i] + b[x];
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (auto e : v) {
        int a = e.second.first, b = e.second.second, w = e.first;
        if (spoji(a, b)) sol -= w;
    }
    cout << sol;
    return 0;
}
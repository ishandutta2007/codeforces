#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int n, H[200005];
vector<int> edge[200005];

ll ans = 0;
int dfs(int x, int p) {
    int mx = 0;
    for (int i : edge[x]) {
        if (i == p) continue;
        int v = dfs(i, x);
        mx = max(mx, v);
    }
    ans += max(0, H[x] - mx);
    return max(H[x], mx);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> H[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int x = max_element(H + 1, H + n + 1) - H;
    vector<int> L(1, 0);
    for (int i : edge[x]) {
        L.push_back(dfs(i, x));
    }
    sort(L.rbegin(), L.rend());
    ans += H[x] * 2 - L[0] - L[1];
    printf("%lld\n", ans);
    return 0;
}
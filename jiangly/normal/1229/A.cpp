#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[i] = __builtin_popcountll(a[i]);
    }
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector<int> perm(n);
    for (int i = 0; i < n; ++i)
        perm[i] = i;
    sort(perm.begin(), perm.end(), [&](int x, int y) {
        return c[x] > c[y] || c[x] == c[y] && a[x] < a[y];
    });
    vector<bool> able(n, false);
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (able[perm[j]] && (a[perm[j]] | a[perm[i]]) == a[perm[j]])
                able[perm[i]] = true;
        if (i < n - 1 && a[perm[i]] == a[perm[i + 1]])
            able[perm[i]] = true;
        if (able[perm[i]])
            ans += b[perm[i]];
    }
    printf("%lld\n", ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
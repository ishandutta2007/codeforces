#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i : p)
        cin >> i;
    sort(p.begin(), p.end(), greater<int>());
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    LL c = 1ll * a * b / __gcd(a, b);
    LL k;
    cin >> k;
    int l = 0, r = n + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int cxy = mid / c, cx = mid / a - cxy, cy = mid / b - cxy;
        LL ans = 0;
        for (int i = 0; i < cxy; ++i)
            ans += p[i] / 100 * (x + y);
        for (int i = cxy; i < cxy + cx; ++i)
            ans += p[i] / 100 * x;
        for (int i = cxy + cx; i < cxy + cx + cy; ++i)
            ans += p[i] / 100 * y;
        if (ans >= k)
            r = mid;
        else
            l = mid + 1;
    }
    if (l == n + 1)
        cout << "-1\n";
    else
        cout << l << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
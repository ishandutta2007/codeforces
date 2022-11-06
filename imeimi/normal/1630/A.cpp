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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<pii> ans;
        if (k == 0) {
            for (int i = 0; i < n / 2; ++i) {
                int a = i;
                int b = (~i) & (n - 1);
                ans.emplace_back(a, b);
            }
        }
        else if (k < n - 1) {
            for (int i = 1; i < n / 2; ++i) {
                int a = i;
                int b = (~i) & (n - 1);
                if (a == k || b == k) continue;
                ans.emplace_back(a, b);
            }
            ans.emplace_back(0, (~k) & (n - 1));
            ans.emplace_back(k, n - 1);
        }
        else if (n > 4) {
            for (int i = 3; i < n / 2; ++i) {
                int a = i;
                int b = (~i) & (n - 1);
                ans.emplace_back(a, b);
            }
            ans.emplace_back(0, 2);
            ans.emplace_back(1, n - 3);
            ans.emplace_back(n - 2, n - 1);
        }
        else printf("-1\n");
        for (auto [a, b] : ans) printf("%d %d\n", a, b);
    }
    return 0;
}
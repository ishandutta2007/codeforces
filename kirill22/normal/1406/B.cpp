#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> big, small;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > 0) big.pb(x);
            else if (x < 0) small.pb(x);
        }
        sort(rall(big));
        sort(all(small));
        int ans = -1e18;
        if (big.size() + small.size() < n) ans = 0;
        for (int i = 0; i <= min(5ll, (int) small.size()); i++) {
            if (5 - i > big.size()) continue;
            if (i % 2 == 0) {
                int res = 1;
                for (int j = 0; j < 5 - i; j++) res *= big[j];
                for (int j = 0; j < i; j++) res *= small[j];
                ans = max(ans, res);
            }
            else {
                int res = 1;
                for (int j = 0; j < 5 - i; j++) res *= big[(int) big.size() - j - 1];
                for (int j = 0; j < i; j++) res *= small[(int) small.size() - j - 1];
                ans = max(ans, res);
            }
        }
        cout << ans << '\n';
    }
}
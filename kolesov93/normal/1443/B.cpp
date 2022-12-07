#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);


int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        string s;
        cin >> a >> b >> s;

        int n = s.size();
        int before = 0;
        bool first = true;
        vector<int> gaps;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                before++;
            } else {
                if (!first) {
                    if (before) {
                        gaps.push_back(before);
                    }
                } else {
                    first = false;
                }
                before = 0;
            }
        }

        if (gaps.empty()) {
            if (first) cout << 0 << endl;
            else cout << a << endl;
        } else {
            sort(begin(gaps), end(gaps));
            int n = gaps.size() + 1;
            ll ans = a * n;

            ll cost = 0;
            for (int i = 0; i + 1 < n; ++i) {
                cost += b * gaps[i];
                ans = min(ans, cost + a * (n - i - 1));
            }
            cout << ans << endl;
        }
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    int sum = 0, sum2 = 0;
    set<int> a, b, small, big;
    while (q--) {
        int t, x;
        cin >> t >> x;
        sum += x;
        if (x < 0) {
            if (t == 0) a.erase(-x);
            else b.erase(-x);
            if (big.find(-x) == big.end()) small.erase(-x);
            else big.erase(-x), sum2 += x;
        }
        else {
            if (t == 0) a.insert(x);
            else b.insert(x);
            if (big.size() == 0 || (*big.begin() >= x)) {
                small.insert(x);
            }
            else {
                big.insert(x), sum2 += x;
            }
        }
        while (big.size() > b.size()) {
            auto x = *big.begin();
            sum2 -= x;
            big.erase(x);
            small.insert(x);
        }
        while (big.size() < b.size()) {
            auto x = *small.rbegin();
            sum2 += x;
            big.insert(x);
            small.erase(x);
        }
        int ans = sum + sum2;
        if (b.size() > 0 && *b.begin() == *big.begin()) {
            ans -= *b.begin();
            if (a.size() > 0) ans += *a.rbegin();
        }
        cout << ans << '\n';
    }
}
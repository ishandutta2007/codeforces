#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;

signed main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        unordered_map<int, int> mpl, mpr;
        for (int i = 1; i <= l; i++) {
            int a;
            cin >> a;
            mpl[a]++;
        }
        for (int i = 1; i <= r; i++) {
            int a;
            cin >> a;
            mpr[a]++;
        }
        int ans = 0;
        vector<int> e1, e2;
        for (auto x:mpl) {
            int col = x.first;
            int num = x.second;
            if (mpr.count(col)) {
                num = min(num, mpr[col]);
                mpl[col] -= num;
                mpr[col] -= num;
                if (mpl[col] == 0) e1.push_back(col);
                if (mpr[col] == 0) e2.push_back(col);
            }
        }
        for (auto x:e1) mpl.erase(x);
        for (auto x:e2) mpr.erase(x);
        e1.clear();
        e2.clear();
        int sum1 = 0, sum2 = 0;
        for (auto x:mpl) sum1 += x.second;
        for (auto x:mpr) sum2 += x.second;
        if (sum1 < sum2) {
            swap(mpl, mpr);
            swap(sum1, sum2);
        }
        int sub = sum1 - sum2;
        for (auto x:mpl) {
            int col = x.first;
            int num = x.second;
            num = num / 2 * 2;
            num = min(num, sub);
            mpl[col] -= num;
            ans += num / 2;
            sub -= num;
            sum1 -= num;
            if (mpl[col] == 0) e1.push_back(col);
        }
        for (auto x:e1) mpl.erase(x);
        ans += abs(sum1 - sum2) / 2;
        ans += (sum1 + sum2) / 2;
        cout << ans << endl;
    }
}
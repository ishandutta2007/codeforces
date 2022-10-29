#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<int> ans;
        ll left = n - 1, s = 1;
        while (2 * s < left) {
            ans.push_back(s);
            s *= 2;
            left -= s;
        }
        if (left >= s) {
            ans.push_back(left - s);
        } else {
            ans.pop_back();
            ans.push_back(left / 2);
            ans.push_back(left - left / 2 * 2);
        }
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }
}
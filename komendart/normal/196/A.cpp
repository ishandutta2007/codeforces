#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string ans;
    for (auto i: s) {
        if (ans.empty() || ans.back() <= i) ans += i;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

}
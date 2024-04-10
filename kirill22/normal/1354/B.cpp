#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define all(a) a.begin(), a.end()

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    map<char, int> a;
    int l = 0;
    for (int i = 0; i < n; i++) {
        a[s[i]]++;
        while (a.size() == 3 && a[s[l]] > 1) {
            a[s[l]]--;
            l++;
        }
        if (a.size() == 3) {
            if (ans == 0) ans = i - l + 1;
            else ans = min(ans, i - l + 1);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
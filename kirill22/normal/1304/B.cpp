#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string ans = "";
    multiset<string> b;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        if (b.find(s2) != b.end()) {
            ans += s;
            b.erase(b.find(s2));
            continue;
        }
        b.insert(s);
    }
    string s2 = "";
    for (auto el : b) {
        string s = el;
        reverse(s.begin(), s.end());
        if (s == el && s.size() > s2.size()) s2 = s;
    }
    cout << ans.size() * 2 + s2.size() << endl;
    cout << ans << s2;
    reverse(ans.begin(), ans.end());
    cout << ans;
}
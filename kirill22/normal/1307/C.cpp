#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    map<char, int> a;
    map<pair<char, char>, int> b;
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        for (auto el : a) {
            b[{c, el.first}] += el.second;
        }
        a[c]++;
    }
    for (auto el : b) {
        ans = max(ans, el.second);
    }
    for (auto el : a) {
        ans = max(ans, el.second);
    }
    cout << ans;
}
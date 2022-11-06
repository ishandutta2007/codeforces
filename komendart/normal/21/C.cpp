#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> s(n + 1);
    unordered_map<int, int> d;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        s[i] = s[i - 1] + t;
        if (d.find(s[i]) == d.end()) d[s[i]] = 0;
        if (i != n) d[s[i]]++;
    }

    int result = 0;
    for (int i = 1; i <= n - 2; i++) {
        d[s[i]]--;
        if (3 * s[i] == s[n]) {
            result += d[2 * s[i]];
        }
    }
    cout << result << '\n';
}
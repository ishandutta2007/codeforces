#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool can[26] = {};
    for (int i = 0; i < k; ++i) {
        char c;
        cin >> c;
        can[c - 'a'] = true;
    }
    long long ans = 0;
    for (int i = 0; i < n; ) {
        if (!can[s[i] - 'a']) {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && can[s[j] - 'a'])
            ++j;
        ans += 1LL * (j - i) * (j - i + 1) / 2;
        i = j;
    }
    cout << ans << endl;
    return 0;
}
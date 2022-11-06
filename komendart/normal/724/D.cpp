#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();

    vector<char> used(n);
    for (int c = 'a'; c <= 'z'; c++) {
        int prev = -1;
        bool flag = true;
        int lastc = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                lastc = i;
            }
            if (used[i]) {
                prev = i;
            }
            if (i - prev == m) {
                if (i - lastc >= m) {
                    flag = false;
                    break;
                }
                used[lastc] = true;
                prev = lastc;
            }
        }
        if (flag) break;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) used[i] = true;
        }
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (used[i]) ans += s[i];
    }
    sort(ans.begin(), ans.end());
    cout << ans << '\n';
}
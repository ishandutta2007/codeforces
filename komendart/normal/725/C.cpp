#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << "Impossible\n";
            return 0;
        }
    }

    int a, b;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                a = i;
                b = j;
            }
        }
    }

    string left = s.substr(0, a);
    string mid = s.substr(a + 1, b - a - 1);
    string right = s.substr(b + 1, n - b - 1);
    vector<string> ans(2, string(13, '#'));
    for (int i = 0; i < 13; i++) {
        if (2 * i + 1 == mid.size() || 2 * i == mid.size()) {
            ans[0][i] = s[a];
            int p = 0;
            for (int j = i - 1; p < mid.size() && j >= 0; j--) {
                ans[0][j] = mid[p++];
            }
            for (int j = 0; p < mid.size(); j++) {
                ans[1][j] = mid[p++];
            }
            string t = right + left;
            p = 0;
            for (int j = i + 1; p < t.size() && j < 13; j++) {
                ans[0][j] = t[p++];
            }
            for (int j = 12; p < t.size(); j--) {
                ans[1][j] = t[p++];
            }
            break;
        }
    }

    for (int i = 0; i < 2; i++) {
        cout << ans[i] << '\n';
    }
}
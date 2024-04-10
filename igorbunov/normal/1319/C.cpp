#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
int dp[100][100];
signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (char now = 'z'; now != 'a'; now--) {
        if (s.size() == 1) {
            break;
        }
        char kek = now - 1;
        string ns;
        ns.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == now && ns.back() == kek) {
                continue;
            }
            ns.push_back(s[i]);
        }
        s = ns;
        reverse(s.begin(), s.end());
        ns.clear();
        ns.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == now && ns.back() == kek) {
                continue;
            }
            ns.push_back(s[i]);
        }
        s = ns;
        reverse(s.begin(), s.end());
    }

    cout << n - s.size();
    /*for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            dp[i][j] = j - i + 1;
        }
    }

    for (int d = 1; d < s.size(); d++) {
        for (int i = 0; i + d < s.size(); i++) {
            int l = i;
            int r = i + d;

            for (int i = l + 1; i < r; i++) {
                if (i != l && (int)s[i - 1] + 1 == (int)s[i]) {
                    dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i + 1][r]);
                }
                if (i != r && (int)s[i + 1] + 1 == (int)s[i]) {
                    dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i + 1][r]);
                }
            }

            if ((int)s[l + 1] + 1 == (int)s[l]) {
                dp[l][r] = min(dp[l][r], dp[l + 1][r]);
            }
            if ((int)s[r - 1] + 1 == (int)s[1]) {
                dp[l][r] = min(dp[l][r], dp[l][r - 1]);
            }
        }
    }

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            cout << dp[l][r] << " ";
        }
        cout << endl;
    }
    cout << s.size() - dp[0][s.size() - 1];*/
    return 0;
}
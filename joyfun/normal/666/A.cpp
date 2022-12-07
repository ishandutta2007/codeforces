#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
using namespace std;

const int N = 10005;
int dp[N][2];
string s;
set<string> ans;

int main() {
    cin >> s;
    int n = s.length();
    dp[n][0] = dp[n][1] = 1;
    for (int i = n - 1; i >= 5; i--) {
        if (i + 2 <= n && dp[i + 2][1]) {
            dp[i][0] = 1;
            ans.insert(s.substr(i, 2));
        }
        if (i + 3 <= n && dp[i + 3][0]) {
            dp[i][1] = 1;
            ans.insert(s.substr(i, 3));
        }
        if (i + 2 <= n && dp[i + 2][0] && s.substr(i, 2) != s.substr(i + 2, 2)) {
            dp[i][0] = 1;
            ans.insert(s.substr(i, 2));
        }
        if (i + 3 <= n && dp[i + 3][1] && s.substr(i, 3) != s.substr(i + 3, 3)) {
            dp[i][1] = 1;
            ans.insert(s.substr(i, 3));
        }
    }
    cout << ans.size() << endl;
    for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << endl;
    return 0;
}
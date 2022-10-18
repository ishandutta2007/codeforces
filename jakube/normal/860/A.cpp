#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;

    int n = s.size();

    auto isC = [](auto c) {
        static string s = "aeiou";
        return count(s.begin(), s.end(), c) == 0;
    };

    int i = 0;

    while (i < n) {
        for (; i < n && !isC(s[i]); i++) {
            cout << s[i];
        }

        vector<char> v;
        for (; i < n && isC(s[i]); i++) {
            v.push_back(s[i]);
        }

        char last = '+';
        string t;
        bool all_equal = true;
        for (char c : v) {
            if (t.size() == 0) {
                t += c;
                all_equal = true;
            } else if (t.size() == 1) {
                t += c;
                all_equal = t.front() == t.back();
            } else {
                if (all_equal && c == t.front()) 
                    t += c;
                else {
                    cout << t << " ";
                    t = c;
                    all_equal = true;
                }

            }
        }
        if (t.size() > 0)
            cout << t;
    }
    cout << endl;

    // vector<vector<int>> dp(n, vector<int>(4, 0));
    // for (int i = 1; i < n; i++) {
    //     // dp[i][0]
    //     if (isC(s[i-1]))


    //     dp[i+1][0] = min(dp[i][0], dp[i][1]);
    // }
}
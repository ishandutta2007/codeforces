#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;

    int cur_a = 0, cur_b = 0;
    int last_a = 0, last_b = 0;

    vector<pair<int, int>> dp(n + 1);
    dp[0] = {0, 0};

    vector<int> psum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        swap(cur_a, last_a);
        swap(cur_b, last_b);
        if (s[i] == 'a')
            cur_a++;
        if (s[i] == 'b')
            cur_b++;
        if (s[i] == '?')
            psum[i + 1] = psum[i] + 1;
        else
            psum[i + 1] = psum[i];

        if (i - m >= 0) {
            if (m % 2 == 0) {
                if (s[i - m] == 'a')
                    cur_a--;
                if (s[i - m] == 'b')
                    cur_b--;
            } else {
                if (s[i - m] == 'a')
                    last_a--;
                if (s[i - m] == 'b')
                    last_b--;
            }
        }

        dp[i + 1] = dp[i];
        if (i + 1 >= m) {
            auto x = dp[0];
            if (m % 2 == 1 && cur_b == 0 && last_a == 0) {
                x = dp[i + 1 - m];
                x.first++;
                x.second += psum[i + 1] - psum[i + 1 - m];
            }
            if (m % 2 == 0 && cur_a == 0 && last_b == 0) {
                x = dp[i + 1 - m];
                x.first++;
                x.second += psum[i + 1] - psum[i + 1 - m];
            }
            if (x.first > dp[i + 1].first)
                dp[i + 1] = x;
            if (x.first == dp[i + 1].first && x.second < dp[i + 1].second)
                dp[i + 1] = x;
        }
    }
    cout << dp.back().second << '\n';
}
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int order[26];
int dp[26];
int answer = 1;

void change(int c) {
    int prev = order[25];
    for (int i = 24; i >= 0; i--) {
        if (order[25] == c) break;
        int t = order[i];
        order[i] = prev;
        if (t == c) {
            order[25] = c;
            break;
        }
        prev = t;
    }
    int x = answer - dp[c];
    dp[c] = answer;
    answer += x;
    answer %= MOD;
    if (answer < 0) answer += MOD;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int m = t.size();

    for (int i = 0; i < 26; i++) order[i] = i;

    for (int i = 0; i < m; i++) {
        change(t[i] - 'a');
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (order[j] < k) {
                change(order[j]);
                break;
            }
        }
    }

    cout << answer << '\n';
}
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int alpha = 26;
const int kmax = 110;
const int inf = 1e9;

int cost[alpha][alpha];
int dp[2][kmax][alpha];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    string s;
    cin >> s;
    int n = sz(s);
    int k;
    cin >> k;

    int q;
    cin >> q;
    while (q--) {
        char x, y;
        cin >> x >> y;
        cin >> cost[x - 'a'][y - 'a'];
    }

    for (int c = 0; c < alpha; ++c) {
        for (int j = 0; j <= k; ++j) {
            dp[0][j][c] = -inf;
        }
        if (c == s[0] - 'a') {
            dp[0][0][c] = 0;
        } else {
            dp[0][1][c] = 0;
        }
    }

    int ptr = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int c = 0; c < alpha; ++c) {
                dp[ptr ^ 1][j][c] = -inf;
            }
        }
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x < alpha; ++x) {
                for (int y = 0; y < alpha; ++y) {
                    int val = dp[ptr][j][x];
                    int newk = j;
                    if (y != s[i] - 'a') {
                        newk = j + 1;
                    }
                    val += cost[x][y];
                    if (newk <= k) {
                        dp[ptr ^ 1][newk][y] = max(dp[ptr ^ 1][newk][y], val);
                    }
                }
            }
        }
        ptr ^= 1;
    }

    int ans = -inf;
    for (int j = 0; j <= k; ++j) {
        for (int c = 0; c < alpha; ++c) {
            ans = max(ans, dp[ptr][j][c]);
        }
    }
    cout << ans << "\n";

}
#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2e5 + 1;
const int inf = 1e9;
int dp[N][2][3], pr[N][2][3];
pair<int, pair<int, int> > pp[N][2][3];
string d[2] = {"one", "two"};


void update(int i, int j, int k, int i1, int j1, int k1, int x) {
    if (dp[i][j][k] > x) {
        dp[i][j][k] = x;
        pp[i][j][k] = {i1, {j1, k1}};
    }
}

void solve() {
    string s;
    int i, j, k, n, l;
    cin >> s;
    vector <int> del;
    for (int i = 0; i <= s.size(); ++i)
    for (int j = 0; j < 2; ++j)
    for (int l = 0; l < 3; ++l)
        dp[i][j][l] = inf;
    dp[0][0][0] = 0;
    for (int i = 0; i < s.size(); ++i)
    for (int j = 0; j < 2; ++j)
    for (int l = 0; l < 3; ++l) {
        update(i + 1, j, l, i, j, l, dp[i][j][l] + 1);
        if (l == 0)
            if (s[i] == d[0][0]) {
                update(i + 1, 0, 1, i, j, l, dp[i][j][l]);
            } else if (s[i] == d[1][0])
                    update(i + 1, 1, 1, i, j, l, dp[i][j][l]);
                else {
                    update(i + 1, 0, 0, i, j, l, dp[i][j][l]);
                }
        if (s[i] == d[j][l]) {
            if (l != 2)
                update(i + 1, j, l + 1, i, j, l, dp[i][j][l]);

        } else {
            if (s[i] == d[0][0]) {
                update(i + 1, 0, 1, i, j, l, dp[i][j][l]);
            } else if (s[i] == d[1][0])
                    update(i + 1, 1, 1, i, j, l, dp[i][j][l]);
                else {
                    update(i + 1, 0, 0, i, j, l, dp[i][j][l]);
                }
        }
    }
    int j1, l1, ans = inf;
    for (j = 0; j < 2; ++j)
    for (l = 0; l < 3; ++l)
    if (dp[s.size()][j][l] < ans) {
        ans = dp[s.size()][j][l];
        j1 = j;
        l1 = l;
    }
    int i1 = s.size();
    while (i1 > 0) {
        pair<int, pair<int, int> > p = pp[i1][j1][l1];
        if (dp[i1 - 1][p.se.fi][p.se.se] < dp[i1][j1][l1]) {
            del.push_back(i1);
        }
        --i1;
        j1 = p.se.fi;
        l1 = p.se.se;
    }
    cout << del.size() << "\n";
    for (i = 0; i < del.size(); ++i)
        cout << del[i] << ' ';
    cout << "\n";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}
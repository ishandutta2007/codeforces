#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

vector<int> g[5000];
vector<int> used;
vector<int> a, b;
pair<vector<int>, vector<int>> mas[5000];
int p = -1;

void dfs(int v, int c) {
    if (c == 1) mas[p].fi.push_back(v);
    else mas[p].se.push_back(v);
    used[v] = c;
    for (auto el : g[v]) {
        if (used[el] == 0) {
            dfs(el, 3 - c);
        }
        else if (used[el] == used[v]) {
            cout << "NO";
            exit(0);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<pair<int, int>> cnt;
    used.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            p++;
            dfs(i, 1);
            cnt.push_back({mas[p].fi.size(), mas[p].se.size()});
        }
    }
    int k = cnt.size();
    vector<vector<int>> dp(k, vector<int> (n + 1, -1));
    vector<vector<int>> pr(k, vector<int> (n + 1, -1));
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            dp[i][cnt[i].fi] = 1;
            dp[i][cnt[i].se] = 1;
            pr[i][cnt[i].fi] = 0;
            pr[i][cnt[i].se] = 0;
            continue;
        }
        for (int j = 0; j <= n; j++) {
            if (dp[i - 1][j] == -1) continue;
            if (j + cnt[i].fi <= n) {
                dp[i][j + cnt[i].fi] = 1;
                pr[i][j + cnt[i].fi] = j;
            }
            if (j + cnt[i].se <= n) {
                dp[i][j + cnt[i].se] = 1;
                pr[i][j + cnt[i].se] = j;
            }
        }
    }
    if (dp[k - 1][n2] == -1) {
        cout << "NO";
        return 0;
    }
    vector<int> ans(n, 0);
    int l = k - 1;
    while (l != -1) {
        int x = pr[l][n2];
        int z = n2 - x;
        if (cnt[l].fi == z) {
            for (auto el : mas[l].fi) {
                ans[el] = 2;
            }
            for (auto el : mas[l].se) {
                if (n1 > 0) {
                    ans[el] = 1;
                    n1--;
                }
                else if (n3 > 0) {
                    ans[el] = 3;
                    n3--;
                }
            }
        }
        else {
            for (auto el : mas[l].se) {
                ans[el] = 2;
            }
            for (auto el : mas[l].fi) {
                if (n1 > 0) {
                    ans[el] = 1;
                    n1--;
                }
                else if (n3 > 0) {
                    ans[el] = 3;
                    n3--;
                }
            }
        }
        l--;
        n2 = x;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i];
}
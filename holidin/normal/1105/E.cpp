#include <bits/stdc++.h>
using namespace std;
const int LogN = 21;
const int N = 1024 * 1024 + 1;

int dp[N], n, t[LogN], ans = 0;
bool c[2 * LogN][2 * LogN];
int pr[2 * LogN];

void rec(int u, int cnt = 0) {
    if (u > n) {
        int x = 0;
        for (int i = 1; i <= n / 2; ++i)
        if (pr[i] == 0)
            x += t[i - 1];
        ans = max(ans, cnt + dp[x]);
        return;
    }
    rec(u + 1, cnt);
    if (pr[u] == 0) {
        for (int i = 1; i <= n; ++i)
            pr[i] += 1 - c[u][i];
        rec(u + 1, cnt + 1);
        for (int i = 1; i <= n; ++i)
            pr[i] -= 1 - c[u][i];
    }
}

map <string, int> ms;

int main() {
    string s;
    int i, j, q, tr, top = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q >> n;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
    if (i != j)
        c[i][j] = true;
    vector <int> e;
    for (i = 0; i < q; ++i) {
        cin >> tr;
        if (tr == 1)
            e.clear();
        else {
            cin >> s;
            if (ms[s] == 0) {
                ++top;
                ms[s] = top;
            }
            int u = ms[s];
            bool flag = false;
            for (j = 0; j < e.size(); ++j)
            if (e[j] == u)
                flag = true;
            else {
                c[e[j]][u] = 0;
                c[u][e[j]] = 0;
            }
            if (!flag)
                e.push_back(u);
        }
    }
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    dp[0] = 0;
    for (i = 1; i < t[n / 2]; ++i) {
        int x = i;
        int h;
        for (h = n / 2 - 1; (x & t[h]) == 0; --h);
        x -= t[h];
        for (j = 0; j < n / 2; ++j)
        if (!c[h + 1][j + 1] && (x & t[j]) > 0)
            x -= t[j];
        dp[i] = max(dp[i - t[h]], dp[x] + 1);
    }
    rec(n / 2 + 1, 0);
    cout << ans;
}
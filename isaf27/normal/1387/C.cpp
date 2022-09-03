//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int X = 55;
const int M = 110;
const ull INF = (ull)1 << (ull)63;

ull sum(ull a, ull b)
{
    if (a == INF || b == INF)
        return INF;
    if (a + b >= INF)
        return INF;
    return a + b;
}

vector<vector<int>> seq[M];
int g, n, m;
vector<string> s;

int to[X][2], r, go[X][2];
bool term[X], good[X];

int exists(string c)
{
    int st = 0;
    for (char x : c)
    {
        int d = x - '0';
        if (to[st][d] == -1)
            return -1;
        st = to[st][d];
    }
    return st;
}

int getsuf(string c)
{
    for (int i = 0; i < (int)c.size(); i++)
    {
        string cur = c.substr(i, (int)c.size() - i);
        int st = exists(cur);
        if (st != -1)
            return st;
    }
    return 0;
}

bool is_good(string c)
{
    for (int i = 0; i < (int)c.size(); i++)
    {
        string cur = c.substr(i, (int)c.size() - i);
        int st = exists(cur);
        if (st != -1 && term[st])
            return false;
    }
    return true;
}

void dfs(int p, string c)
{
    good[p] = is_good(c);
    go[p][0] = getsuf(c + "0");
    go[p][1] = getsuf(c + "1");
    if (to[p][0] != -1)
        dfs(to[p][0], c + "0");
    if (to[p][1] != -1)
        dfs(to[p][1], c + "1");
}

ull dp[M][X][X], cur[2][X];

int main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> g >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, k;
        cin >> a >> k;
        vector<int> c(k);
        for (int t = 0; t < k; t++)
            cin >> c[t];
        seq[a].push_back(c);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        string c = "";
        for (int t = 0; t < k; t++)
        {
            char x;
            cin >> x;
            c += x;
        }
        s.push_back(c);
    }
    memset(to, -1, sizeof(to));
    r = 1;
    for (string c : s)
    {
        int st = 0;
        for (char x : c)
        {
            int d = x - '0';
            if (to[st][d] == -1)
                to[st][d] = r++;
            st = to[st][d];
        }
        term[st] = true;
    }
    dfs(0, "");
    for (int i = 0; i < g; i++)
        for (int j = 0; j < r; j++)
            for (int h = 0; h < r; h++)
                dp[i][j][h] = INF;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < r; j++)
            if (good[j] && good[go[j][i]])
                dp[i][j][go[j][i]] = 1;
    while (TIME < 0.5)
    {
        for (int i = 2; i < g; i++)
            for (int st = 0; st < r; st++)
                if (good[st])
                {
                    for (const vector<int>& ids : seq[i])
                    {
                        for (int l = 0; l < 2; l++)
                            for (int t = 0; t < r; t++)
                                cur[l][t] = INF;
                        cur[0][st] = 0;
                        int now = 0;
                        for (int u : ids)
                        {
                            for (int t = 0; t < r; t++)
                                cur[1 - now][t] = INF;
                            for (int t = 0; t < r; t++)
                                for (int b = 0; b < r; b++)
                                    if (good[t] && good[b])
                                        cur[1 - now][t] = min(cur[1 - now][t], sum(cur[now][b], dp[u][b][t]));
                            now = 1 - now;
                        }
                        for (int t = 0; t < r; t++)
                            dp[i][st][t] = min(dp[i][st][t], cur[now][t]);
                    }
                }
    }
    for (int i = 2; i < g; i++)
    {
        ull ans = INF;
        for (int t = 0; t < r; t++)
            if (good[t])
                ans = min(ans, dp[i][0][t]);
        if (ans == INF)
            cout << "YES\n";
        else
            cout << "NO " << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

vector<vector<int> > W;

vector<int> w;

void rec(int x, int X)
{
    if (x == 0)
    {
        W.push_back(w);
        return;
    }
    for (int y = 1; y <= 9 && y <= x; y++)
    {
        int z = y;
        int t = 1;
        if (z != X && X % z == 0) t = 0;
        for (int i = (int)w.size() - 1; t && i >= 0; i--)
        {
            z += w[i];
            if (z != X && X % z == 0) t = 0;
        }
        if (t)
        {
            w.push_back(y);
            rec(x - y, X);
            w.pop_back();
        }
    }
}

int go[5100][10];
int link[5100];
int sz = 1;
int term[5100];

int dp[1200][5100];

signed main()
{
    string s;
    int x;
    cin >> s >> x;
    rec(x, x);
    for (int i = 0; i < W.size(); i++)
    {
        int pnt = 0;
        for (int j = 0; j < W[i].size(); j++)
        {
            int d = W[i][j];
            if (go[pnt][d] == 0)
            {
                go[pnt][d] = sz;
                sz++;
            }
            pnt = go[pnt][d];
        }
        term[pnt] = 1;
    }
    vector<int> q = {0};
    for (int i = 0; i < q.size(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (go[q[i]][j] != 0)
            {
                int b = link[q[i]];
                int d = j;
                while (b != 0 && go[b][d] == 0)
                {
                    b = link[b];
                }
                if (go[b][d] != go[q[i]][j])
                link[go[q[i]][j]] = go[b][d];
                q.push_back(go[q[i]][j]);
            }
        }
    }
    for (auto i : q)
    {
        for (int j = 0; j < 10; j++)
        {
            int z = i;
            while (z != 0 && go[z][j] == 0)
            {
                z = link[z];
            }
            go[i][j] = go[z][j];
        }
    }
    vector<int> a(s.size());
    for (int i = 0; i < a.size(); i++) a[i] = s[i] - '0';
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j < sz; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < sz; j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            int z = go[j][a[i]];
            if (!term[z]) dp[i + 1][z] = min(dp[i + 1][z], dp[i][j]);
        }
    }
    int ans = 1e9;
    for (int j = 0; j < sz; j++) ans = min(ans, dp[a.size()][j]);
    cout << ans;
}
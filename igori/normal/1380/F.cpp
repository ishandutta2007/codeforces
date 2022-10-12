#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 506070;
const int MOD = 998244353;

int n, m;
string s;
vector<int> c;

int ways[100];

struct Node{
    int a[2][2];
};

Node dp[4 * N];

void Build(int L = 0, int R = n, int V = 0)
{
    if (L + 1 == R)
    {
        dp[V].a[0][0] = ways[c[L]];
        dp[V].a[0][1] = 1;
        dp[V].a[1][0] = 1;
        return;
    }
    int M = (L + R) / 2;
    Build(L, M, 2 * V + 1);
    Build(M, R, 2 * V + 2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[V].a[i][j] = 1ll * dp[2 * V + 1].a[i][0] * dp[2 * V + 2].a[0][j] % MOD;
            if (c[M - 1] == 1)
                dp[V].a[i][j] = (dp[V].a[i][j] + 1ll * dp[2 * V + 1].a[i][1] * ways[10 + c[M]] % MOD * dp[2 * V + 2].a[1][j]) % MOD;
        }
    }
}

void Set(int pos, int x, int L = 0, int R = n, int V = 0)
{
    if (L + 1 == R)
    {
        dp[V].a[0][0] = ways[c[L]];
        dp[V].a[0][1] = 1;
        dp[V].a[1][0] = 1;
        return;
    }
    int M = (L + R) / 2;
    if (pos < M) Set(pos, x, L, M, 2 * V + 1);
    else Set(pos, x, M, R, 2 * V + 2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[V].a[i][j] = 1ll * dp[2 * V + 1].a[i][0] * dp[2 * V + 2].a[0][j] % MOD;
            if (c[M - 1] == 1)
                dp[V].a[i][j] = (dp[V].a[i][j] + 1ll * dp[2 * V + 1].a[i][1] * ways[10 + c[M]] % MOD * dp[2 * V + 2].a[1][j]) % MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ways[i + j]++;
        }
    }
    cin >> n >> m;
    cin >> s;
    c.resize(n);
    for (int i = 0; i < n; i++)
    {
        c[i] = s[i] - '0';
    }
    if (n > 1) Build();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        c[x] = y;
        if (n > 1)
        {
            Set(x, y);
            cout << dp[0].a[0][0] << "\n";
        }
        else
        {
            cout << ways[c[0]] << "\n";
        }
    }
}
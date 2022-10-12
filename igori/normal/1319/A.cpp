#include <bits/stdc++.h>

// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\
// "We created a community that can control itself." \\
// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\

// TechnoRush

using namespace std;

#define all(x) (x).begin(), (x).end()

const long long MOD = 1e9 + 7;
const long long INFLL = 1e18;
const long long INF = 1e9;
const int N = 500;

long long inq(long long x, long long y)
{
    if (y == 0) return 1;
    long long l = inq(x, y / 2);
    if (y % 2) return l * l % MOD * x % MOD;
    return l * l % MOD;
}

long long fact[N], ufact[N], r[N];
int erato[N];

long long cnk(long long n, long long k)
{
    return fact[n] * ufact[k] % MOD * ufact[n - k] % MOD;
}

void factorials()
{
    r[1] = 1;
    for (int i = 2; i < N; i++) r[i] = (MOD - (MOD / i) * r[MOD % i] % MOD) % MOD;
    fact[0] = 1, ufact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD, ufact[i] = ufact[i - 1] * r[i] % MOD;
}

void eratos()
{
    for (int i = 2; i < N; i++)
        if (erato[i] == 0)
            for (int j = i; j < N; j += i) erato[j] = i;
}

int ok(int i, int n)
{
    if (i < 0 || i >= n) return 0;
    return 1;
}

int root[N], sz[N];

int Root(int x)
{
    if (x == root[x]) return x;
    return root[x] = Root(root[x]);
}

int Merge(int v, int u)
{
    v = Root(v), u = Root(u);
    if (v == u) return 0;
    if (sz[v] < sz[u])
    {
        sz[u] += sz[v];
        root[v] = u;
    }
    else
    {
        sz[v] += sz[u];
        root[u] = v;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 0) cnt++;
    }
    if (cnt == 0)
    {
        cout << -1;
        exit(0);
    }
    int score1 = 0, score2 = 0;
    for (int i = 0; i < n; i++) score1 += a[i];
    for (int i = 0; i < n; i++) score2 += b[i];
    for (int r = 1; r < 1000; r++)
    {
        if (cnt * r + score1 - cnt > score2)
        {
            cout << r;
            exit(0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    eratos();
    factorials();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

const int MAXN = 2e3;
const int MOD = 998244353;
int kapitan[MAXN];
int rozmiar[MAXN];
int krawedzi[MAXN];
vector<int> res[MAXN];

vector<int> combine(vector<int> X1, vector<int> X2)
{
    vector<int> res(sz(X1));
    rep(i, sz(X2)) if (X2[i]) rep(j, sz(X1)) if (X1[j]) res[i + j] = (res[i + j] + X2[i] * X1[j]) % MOD;
    return res;
}

int find(int x)
{
    return kapitan[x] == x ? x : kapitan[x] = find(kapitan[x]);
}
int po(int x)
{
    return x * (x - 1) / 2;
}

void unia(int a, int b)
{
    int y = find(a);
    int x = find(b);
    if (x != y)
    {
        if (rozmiar[x] < rozmiar[y])
            swap(x, y);
        kapitan[y] = x;
        res[x] = combine(res[x], res[y]);
        rozmiar[x] += rozmiar[y];
        krawedzi[x] += krawedzi[y];
    }
    krawedzi[x]++;

    if (krawedzi[x] == po(rozmiar[x]))
        res[x][1] = 1;
}

int32_t main()
{
    _upgrade;

    priority_queue<pair<int, pii>> Q;
    int n;
    cin >> n;

    rep(i, MAXN)
    {
        kapitan[i] = i;

        res[i].resize(n + 1, 0);
        res[i][1] = 1;
        rozmiar[i] = 1;
    }

    rep(i, n) rep(j, n)
    {
        int a;
        cin >> a;
        if (i > j)
            Q.push({-a, {i, j}});
    }
    while (!Q.empty())
    {
        auto q = Q.top();
        Q.pop();
        unia(q.nd.st, q.nd.nd);
    }

    int x = find(0);
    for (int i = 1; i <= n; i++)
        cout << res[x][i] << " ";
    cout << endl;
}
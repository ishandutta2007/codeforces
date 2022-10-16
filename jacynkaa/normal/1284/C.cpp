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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

const int MAXN = 5e5;
int tab[MAXN];

int n, m;

void pre()
{
    cin >> n >> m;
    tab[0] = 1;
    rep(i, n + 20)
        tab[i + 1] = (tab[i] * (i + 1)) % m;
}
inline int modd(int a, int b)
{
    return (a * b) % m;
}

void solve()
{
    int odp = 0;
    for (int k = 1; k <= n; k++)
    {
        //cerr << k << " " << odp << endl;
        odp = (odp + modd(modd(tab[n - k + 1], n - k + 1), tab[k])) % m;
    }
    cout << odp << endl;
}

main()
{
    _upgrade;
    pre();
    solve();
}
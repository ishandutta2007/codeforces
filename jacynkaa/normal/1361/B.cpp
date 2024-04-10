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
const int MOD = 1e9 + 7;

int fpw(int a, int b, int p)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
            r = r * a % p;
        a = a * a % p;
        b /= 2;
    }
    return (int)r;
}

int get_fpw(int a, int b)
{
    // what(a);
    // what(b);
    if (a > 1 && (b > 30 || pow(a, b) >= MOD))
        return fpw(a, b, MOD) + MOD;
    return fpw(a, b, MOD);
}

int mult(int a, int b)
{
    int res = a * b;
    return res > MOD ? res % MOD + MOD : res;
}

int32_t main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {
        int n, p;
        cin >> n >> p;
        vector<int> X(n);
        rep(i, n) cin >> X[i];
        sort(all(X), greater<int>());
        int res = 0;

        rep(i, n)
        {
            if (i)
                res = mult(res, get_fpw(p, X[i - 1] - X[i]));
            if (res == 0)
                res++;
            else
                res--;
            //  what(res);
        }
        res = mult(res, get_fpw(p, X.back()));
        cout << res % MOD << endl;
    }
}
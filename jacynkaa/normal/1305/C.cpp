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
#define LL long long
#define int long long

LL fpw(LL a, LL b, LL p)
{
    LL r = 1;
    while (b)
    {
        if (b & 1)
            r = r * a % p;
        a = a * a % p;
        b /= 2;
    }
    return (LL)r;
}

main()
{
    _upgrade;
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    if (n > 3 * m)
    {
        cout << 0 << endl;
        exit(0);
    }
    int ans = 1;
    rep(i, n) for (int j = i + 1; j < n; j++) ans = (ans * (abs(A[i] - A[j]))) % m;
    cout << ans << endl;
}
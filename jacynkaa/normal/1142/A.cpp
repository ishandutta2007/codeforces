#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
//#pragma GCC optimize (-O3)
//#define endl tutaj n
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long

int n, k, a, b;
int mak = 0;
int mini = 1e18;

void foo(int s)
{
    for (int i = 0; i < 5 * n + 10; i++)
    {
        s += k;
        int z = __gcd(n * k, s);
        mak = max(mak, z);
        mini = min(mini, z);
    }
}

main()
{
    _upgrade;
    cin >> n >> k;
    cin >> a >> b;
    foo(a + b + 2 * k);
    foo(a - b + 2 * k);
    foo(-a + b + 2 * k);
    foo(-a - b + 2 * k);
    cout << n * k / mak << " " << n * k / mini << endl;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ld eps = 1e-8;
const ld pi = acos(-1.0);
const int M = 3 * 1e4;
const int two = 2;
const ll prime = 239;
const int BIG = 1e9 + 239;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int th = 3;
const int MS = (1 << 20);

ll func(ll n)
{
    ll ans = (n * (n + 1)) >> 1LL;
    ll r = 1;
    while (n)
    {
        n /= 2;
        r *= 2;
    }
    return (ans - 2 * (r - 1));
}

int main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll f;
        cin >> f;
        cout << func(f) << "\n";
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

ll n, k, d1, d2;

ll f(ll x1, ll x2, ll x3)
{
    ll g = k - x1 - x2 - x3;
    if (g < 0) return -1;
    if (g % 3) return -1;
    return g / 3;
}

bool go(ll a, ll b, ll c)
{
    return a >= 0 && b >= 0 && c >= 0 && a <= n && b <= n && c <= n;
}

int main()
{

    int tt;
    cin >> tt;

    while (tt--)
    {
        cin >> n >> k >> d1 >> d2;
        if (n % 3) cout << "no\n";
        else
        {
            n /= 3;
            ll b;
            bool ans = false;
            for (ll k1 = -1; k1 <= 1; k1 += 2)
                for (ll k2 = -1; k2 <= 1; k2 += 2)
            {
                b = f(k1 * d1, 0, k2 * d2);
                if (!ans && go(b + k1 * d1, b, b + k2 * d2))
                {
                    cout << "yes\n";
                    ans = true;
                }
            }
            if (!ans) cout << "no\n";
        }
    }

}
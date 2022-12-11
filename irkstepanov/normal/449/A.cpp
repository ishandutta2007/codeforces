#include <iostream>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

ll n, m, k;

ll f (ll a)
{
    if (a >= k + 1) a = k + 1;
    ll b = k + 2 - a;
    return (n / a) * (m / b);
}

int main()
{

    cin >> n >> m >> k;

    ll x = (ll) sqrt(n * 1.0);

    ll ans = -1;
    if (n + m - 2 < k)
    {
        cout << ans;
        return 0;
    }

    for (ll a = 1; a <= x; a++)
        ans = max(ans, max(f(a), f(n / a)));

    cout << ans;

}
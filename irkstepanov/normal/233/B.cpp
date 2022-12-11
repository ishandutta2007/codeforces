#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <set>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll d = 1000000ll;

ll s (ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

int main()
{

    ll n;
    cin >> n;

    ll xr = (ll) sqrt(n) + 5;

    for (ll x = xr; x >= xr - d && x >= 0; x--)
        if (x * x + s(x) * x == n) {cout << x << "\n"; return 0;}

    cout << "-1\n";
    return 0;

}
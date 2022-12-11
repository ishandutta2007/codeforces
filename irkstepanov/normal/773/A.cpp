#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ll inf = 1e9 + 100;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        ll g = __gcd(p, q);
        p /= g, q /= g;
        ll lf = -1, rg = inf;
        while (rg - lf > 1) {
            ll md = (lf + rg) >> 1;
            ll a = md * q - y;
            ll b = md * p - x;
            if (a >= 0 && b >= 0 && b <= a) {
                rg = md;
            } else {
                lf = md;
            }
        }
        if (rg == inf) {
            cout << "-1\n";
        } else {
            cout << rg * q - y << "\n";
        }
    }

}
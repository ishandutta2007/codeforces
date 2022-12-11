#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll inf = (ll)(1e9);

ll n;
ll x, y;

void step(ll maxS, ll dx, ll dy)
{
    ll s = min(n, maxS);
    x += dx * s;
    y += dy * s;
    n -= s;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    cin >> n;

    ll kmax = inf, kmin = 0;
    while (kmax - kmin > 1) {
        ll k = (kmax + kmin) / 2;
        ll x = 3 * k * (k + 1);
        if (x > n) {
            kmax = k;
        } else {
            kmin = k;
        }
    }
    ll k = kmin;///k -- full
    n -= 3 * k * (k + 1);

    x = 2 * k, y = 0;
    step(1, 1, 2);
    ++k;

    step(k - 1, -1, 2);
    step(k, -2, 0);
    step(k, -1, -2);
    step(k, 1, -2);
    step(k, 2, 0);
    step(k, 1, 2);

    cout << x << " " << y << "\n";

}
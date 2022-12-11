#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

ll n, m;

bool inside(ll x, ll y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

ll area(ll a, ll b, ll c, ll d)
{
    ll x = abs(c - a) + 1, y = abs(d - b) + 1;
    return x * y;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n >> m;
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        ll dx = -a, dy = -b;
        if (inside(c + dx, d + dy)) {
            c += dx, d += dy;
            ll x = n - c, y = m - d;
            ll ans = (ll)(2) * x * y;
            if (x - 1 >= c && y - 1 >= d) {
                ans -= area(c, d, x - 1, y - 1);
            }
            cout << n * m - ans << "\n";
            continue;
        }
        dx = n - 1 - a, dy = -b;
        if (inside(c + dx, d + dy)) {
            c += dx, d += dy;
            ll x = c + 1, y = m - d;
            ll ans = (ll)(2) * x * y;
            if (n - x <= c && y - 1 >= d) { //////false!!!!!!!!!!!!!!!!
                ans -= area(c, d, n - x, y - 1);
            }
            //lol bred
            cout << n * m - ans << "\n";
            continue;
        }
        dx = -a, dy = m - 1 - b;
        if (inside(c + dx, d + dy)) {
            c += dx, d += dy;
            ll x = n - c, y = d + 1;
            ll ans = (ll)(2) * x * y;
            if (x - 1 >= c && m - y <= d) {
                ans -= area(c, d, x - 1, m - y);
            }
            cout << n * m - ans << "\n";
            continue;
        }
        dx = n - 1 - a, dy = m - 1 - b;
        if (inside(c + dx, d + dy)) {
            c += dx, d += dy;
            ll x = c + 1, y = d + 1;
            ll ans = (ll)(2) * x * y;
            if (n - x <= c && m - y <= d) {
                ans -= area(c, d, n - x, m - y);
            }
            cout << n * m - ans << "\n";
        }
    }

}
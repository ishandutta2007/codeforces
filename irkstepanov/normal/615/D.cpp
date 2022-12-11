#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll MOD = (ll)(1e9 + 7);

void mult(ll& a, ll b, ll mod)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

ll pw(ll x, ll n, ll mod)
{
    if (!n) {
        return 1;
    }
    ll ans = 1;
    while (n) {
        if (n % 2) {
            mult(ans, x, mod);
        }
        mult(x, x, mod);
        n /= 2;
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n;
    cin >> n;

    map<int, int> p;
    while (n--) {
        int x;
        cin >> x;
        ++p[x];
    }

    ll cnt = 1;
    for (map<int, int>::iterator it = p.begin(); it != p.end(); ++it) {
        mult(cnt, 1 + it->second, 2 * MOD - 2);
    }

    ll ans = 1;
    for (map<int, int>::iterator it = p.begin(); it != p.end(); ++it) {
        ll deg = cnt;
        mult(deg, it->second, 2 * MOD - 2);
        deg /= 2;
        ll x = pw(it->first, deg, MOD);
        mult(ans, x, MOD);
    }

    cout << ans << "\n";

}
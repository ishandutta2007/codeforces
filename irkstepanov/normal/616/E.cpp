#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
//#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const ll mod = (ll)(1e9 + 7);
const ll r2 = 500000004;
const ll much = (ll) (1e5) * mod;

void add(ll& a, ll b)
{
    a += b;
    if (a >= much) {
        a -= much;
    }
}

void ret(ll& a, ll b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

ll mult(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

ll f(ll x, ll y)
{
    ll sum = y;
    if (sum >= mod) {
        sum %= mod;
    }
    ll dy = y + 1;
    if (dy >= mod) {
        dy %= mod;
    }
    mult(sum, dy);
    mult(sum, r2);
    --x;
    ll det = x;
    if (det >= mod) {
        det %= mod;
    }
    ll dx = x + 1;
    if (dx >= mod) {
        dx %= mod;
    }
    mult(det, dx);
    mult(det, r2);
    ret(sum, det);
    return sum;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //freopen("mine.txt", "w", stdout);

    ll n, m;
    cin >> n >> m;

    ll ans = n % mod;
    mult(ans, m % mod);
    if (m > n) {
        m = n;
    }
    ll bad = 0;

    ll lasti;
    ll i;
    for (i = 1; i * i <= n && i <= m; ++i) {
        ll x = n / i;
        if (x >= mod) {
            x %= mod;
        }
        mult(x, i);
        add(bad, x);
        lasti = n / i;
    }
    if (i == m + 1) {
        goto pitri;
    }

    for (ll c = 1; c < lasti; ++c) {
        ll x = n / (c + 1) + 1;
        ll y = n / c;
        if (x > m) {
            continue;
        }
        x = min(x, m);
        y = min(y, m);
        ll t = f(x, y);
        mult(t, c);
        add(bad, t);
    }
    pitri:
    bad += much;
    bad %= mod;
    ret(ans, bad);
    cout << ans << "\n";


}
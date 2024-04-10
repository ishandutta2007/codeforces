#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

void sub(ll& a, ll b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

ll binpow(ll a, ll n)
{
    if (n == 0) {
        return 1;
    }
    ll ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        if (n) {
            mul(a, a);
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ll a, b, n, x;
    cin >> a >> b >> n >> x;

    ll ans = binpow(a, n);
    mul(ans, x);

    ll val;
    if (a == 1) {
        val = n % mod;
    } else {
        val = binpow(a, n);
        sub(val, 1);
        mul(val, binpow(a - 1, mod - 2));
    }

    mul(val, b);
    add(ans, val);

    cout << ans << "\n";

}
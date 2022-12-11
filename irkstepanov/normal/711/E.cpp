#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int mod = 1e6 + 3;

void mul(ll& a, ll b)
{
    a *= b;
    a %= mod;
}

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
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
    ll ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll curr = 1;
    for (ll i = 0; i < n; ++i) {
        curr *= ll(2);
        if (curr >= k) {
            break;
        }
    }
    if (curr < k) {
        cout << "1 1\n";
        return 0;
    }

    ll deg2 = n % (mod - 1);
    ll subtr = 0;
    deg2 *= (k % (mod - 1));
    deg2 %= (mod - 1);

    for (ll i = 2; ; i *= 2) {
        ll val = (k - 1) / i;
        if (!val) {
            break;
        }
        val %= (mod - 1);
        deg2 -= val;
        subtr += val;
        if (subtr >= mod - 1) {
            subtr -= (mod - 1);
        }
        if (deg2 < 0) {
            deg2 += mod - 1;
        }
    }
    deg2 -= (n % (mod - 1));
    subtr += (n % (mod - 1));
    if (subtr >= mod - 1) {
        subtr -= (mod - 1);
    }
    if (deg2 < 0) {
        deg2 += mod - 1;
    }

    ll b = binpow(2, deg2);
    ll a;
    if (k >= mod) {
        a = 0;
    } else {
        ll val = binpow(2, n);
        a = val;
        for (ll i = 1; i < k; ++i) {
            sub(val, 1);
            mul(a, val);
        }
    }
    mul(a, binpow(2, subtr * (mod - 2)));

    a = b - a;
    if (a < 0) {
        a += mod;
    }
    cout << a << " " << b << "\n";

}
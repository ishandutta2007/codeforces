#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define forn(i, n) for (int (i) = 0; (i) < n; ++(i))
#define ford(i, n) for (int (i) = (n) - 1; (i) >= 0; --(i))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

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

const int nmax = 100500;

ll fact[nmax], rfact[nmax];

ll bin(int n, int k)
{
    if (n < k) {
        return 0;
    }
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }

    vector<vector<int> > divisors(nmax);

    for (int i = 1; i < nmax; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                divisors[i].pb(j);
                if (j * j != i) {
                    divisors[i].pb(i / j);
                }
            }
        }
        sort(all(divisors[i]));
    }

    int tt;
    cin >> tt;

    vector<ll> m(nmax);

    while (tt--) {
        ll n, f;
        cin >> n >> f;
        for (int k : divisors[n]) {
            if ((ll)k < f) {
                continue;
            }
            ll val = bin(k - 1, f - 1);
            for (int l : divisors[k]) {
                sub(val, m[l]);
            }
            m[k] = val;
        }
        cout << m[n] << "\n";
        for (int k : divisors[n]) {
            m[k] = 0;
        }
    }

}
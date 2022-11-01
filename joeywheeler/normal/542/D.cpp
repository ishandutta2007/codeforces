#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll mulmod(ll a, ll n, ll mod) {
    ll result = 0;
    while (n) {
        if (n & 1) result = (result+a)%mod;
        a = (a + a) % mod;
        n >>= 1;
    }
    return result;
}

// calcul a^n%mod
ll power(ll a, ll n, ll mod)
{
    ll power = a;
    ll result = 1;

    while (n)
    {
        if (n & 1)
            result = mulmod(result, power, mod);
        power = mulmod(power, power, mod);
        n >>= 1;
    }
    return result;
}

// n1 = 2^s * d with d odd by factoring powers of 2 from n1
bool witness(ll n, ll s, ll d, ll a)
{
    ll x = power(a, d, n);
    ll y;

    while (s) {
        y = mulmod(x,x,n);
        if (y == 1 && x != 1 && x != n-1)
            return false;
        x = y;
        --s;
    }
    if (y != 1)
        return false;
    return true;
}

bool is_prime_mr(ll n)
{
    if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3)
        return true;

    ll d = n / 2;
    ll s = 1;
    while (!(d & 1)) {
        d /= 2;
        ++s;
    }

    if (n < 1373653)
        return witness(n, s, d, 2) && witness(n, s, d, 3);
    if (n < 9080191)
        return witness(n, s, d, 31) && witness(n, s, d, 73);
    if (n < 4759123141)
        return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
    if (n < 1122004669633)
        return witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803);
    if (n < 2152302898747)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11);
    if (n < 3474749660383)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13);
    return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13) && witness(n, s, d, 17);
}

vector<ll> f;
vector<ll> res;
ll a;

void go(vector<ll> p) {
    for (int i = sz(f)-1; i >= 0; i--) {
        ll v = f[i];
        for (ll x : p) if (v%x == 0) {
            ll nv =  v/x;
            res[i] += res[lower_bound(f.begin(),f.end(),nv)-f.begin()];
        }
    }
}

int main() {
    scanf("%lld", &a);
    for (ll v = 1; v*v <= a; v++) if (a%v == 0) {
        f.push_back(v);
        if (v*v != a) f.push_back(a/v);
    }
    sort(f.begin(), f.end());
    res.resize(sz(f));

    res[0] = 1;

    map<ll,vector<ll> > m;

    for (ll v : f) {
        if (v == 1) continue;
        v--;
        // is v of the form p^k
        for (int k = 1; (1ll<<k) <= v; k++) {
            ll val = pow(v,1./k);
            if (k == 1) val = v;
            else {
                while (pow(val,k) >= 1e15 || power(val,k,1ll<<62) >= v) val--;
                for (val = max(val-5,0ll); pow(val,k) < 1e15 && power(val,k,1ll<<62) < v; val++);
            }
            if (pow(val,k) < 1e15 && power(val,k,1ll<<62) == v && is_prime_mr(val)) {
                //printf("r %lld: %lld\n", val, v+1);
                m[val].push_back(v+1);
            }
        }
    }

    for (auto p : m) {
        go(p.second);
    }

    printf("%lld\n", res.back());
}
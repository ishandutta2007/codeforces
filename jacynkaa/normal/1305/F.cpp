#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;

ull mod_mul(ull a, ull b, ull M)
{
    ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull mod_pow(ull b, ull e, ull mod)
{
    ull ans = 1;
    for (; e; b = mod_mul(b, b, mod), e /= 2)
        if (e & 1)
            ans = mod_mul(ans, b, mod);
    return ans;
}

ull pollard(ull n)
{
    auto f = [n](ull x) { return (mod_mul(x, x, n) + 1) % n; };
    if (!(n & 1))
        return 2;
    for (ull i = 2;; i++)
    {
        ull x = i, y = f(x), p;
        while ((p = __gcd(n + y - x, n)) == 1)
            x = f(x), y = f(f(y));
        if (p != n)
            return p;
    }
}

bool isPrime(ull n)
{
    if (n < 2 || n % 6 % 4 != 1)
        return n - 2 < 2;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n - 1), d = n >> s;
    for (int a : A)
    {
        //  count t r a i l i n g zeroes
        ull p = mod_pow(a, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = mod_mul(p, p, n);
        if (p != n - 1 && i != s)
            return 0;
    }
    return 1;
}

vector<ull> factor(ull n)
{
    if (n == 1)
        return {};
    if (isPrime(n))
        return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

pair<ll, ll> close(ll a, ll p)
{
    if (a < p)
    {
        return make_pair(p, p - a);
    }
    ll x = a % p;
    if (x > (p - x))
        return {a - x + p, p - x};
    else
        return {a - x, x};
}

main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    _upgrade;
    int n;
    cin >> n;
    vector<long long> X(n);
    rep(i, n) cin >> X[i];
    long long odp = n + 2;

    shuffle(all(X), rng);

    for (int i = 0; i < min(30, (int)X.size()); i++)
    {
        auto V = {factor(X[i] + 1),
                  factor(max(X[i] - 1, 1ll)),
                  factor(X[i])};

        set<long long> S;
        for (auto Q : V)
            for (ll a : Q)
                S.insert(a);
        for (ll p : S)
        {
            long long cur = 0;
            for (long long x : X)
                cur += close(x, p).nd;
            odp = min(odp, cur);
        }
    }

    cout << odp << endl;
}
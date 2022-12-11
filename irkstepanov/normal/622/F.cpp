#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <queue>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mult(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

ll binpow(ll a, ll n)
{
    ll ans = 1;
    while (n) {
        if (n & 1) {
            mult(ans, a);
        }
        mult(a, a);
        n >>= 1;
    }
    return ans;
}

void divide(ll& a, ll b)
{
    mult(a, binpow(b, mod - 2));
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    ll n;
    int k;
    cin >> n >> k;

    vector<ll> y(k + 2);///y[i] == P(i) == 1^k + 2^k + ... + i^k
    for (int i = 1; i <= k + 1; ++i) {
        ll t = binpow(i, k);
        y[i] = y[i - 1];
        add(y[i], t);
    }

    if (n <= k + 1) {
        cout << y[n] << "\n";
        return 0;
    }

    ll p = 1;
    for (int i = 1; i <= k + 1; ++i) {
        mult(p, n - i);
        divide(p, mod - i);
    }

    ll ans = 0;
    ll t = p;
    mult(t, y[0]);
    add(ans, t);

    for (int i = 1; i <= k + 1; ++i) {
        mult(p, n - (i - 1));
        divide(p, n - i);
        divide(p, i);
        mult(p, mod + i - k - 2);
        t = p;
        mult(t, y[i]);
        add(ans, t);
    }

    cout << ans << "\n";

}
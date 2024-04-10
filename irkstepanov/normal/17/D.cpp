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
typedef pair<ll, int> pll;

int rem(const string& s, int mod)
{
    ll res = 0;
    for (int i = 0; i < sz(s); ++i) {
        res *= 10;
        res += (s[i] - '0');
        if (res >= mod) {
            res %= mod;
        }
    }
    return res;
}

int fi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans /= i;
            ans *= (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) {
        ans /= n;
        ans *= (n - 1);
    }
    return ans;
}

ll binpow(ll a, ll n, ll mod)
{
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % mod;
        }
        n >>= 1;
        if (n) {
            a = (a * a) % mod;
        }
    }
    return ans;
}

ll str_to_ll(const string& s)
{
    ll ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        ans *= 10;
        ans += (s[i] - '0');
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string b, n;
    int c;
    cin >> b >> n;
    cin >> c;

    ll ans = rem(b, c);
    --ans;
    if (ans < 0) {
        ans += c;
    }

    int d = fi(c);

    int p = rem(n, d);
    --p;
    if (p < 0) {
        p += d;
    }

    if (sz(n) >= 12 || str_to_ll(n) - 1 >= d) {
        p += d;
    }

    ll q = rem(b, c);
    ans *= binpow(q, p, c);
    ans %= c;

    cout << (ans == 0 ? c : ans) << "\n";

}
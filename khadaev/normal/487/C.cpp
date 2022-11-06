#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

vector<int> primes(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.eb(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) ans.eb(n);
    return ans;
}

ll Pow(ll a, ll b, int n) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2)
            x = x * y % n;
        y = y * y % n;
        b /= 2;
    }
    return x;
}

int gen(int p) {
    vector<int> divs = primes(p - 1);
    for (int i = 1; i < p; ++i) {
        bool ok = true;
        for (int d : divs)
            if (Pow(i, (p - 1) / d, p) == 1)
                ok = false;
        if (ok)
            return i;
    }
    exit(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES\n";
        cout << "1\n";
        return 0;
    }
    if (n == 2) {
        cout << "YES\n";
        cout << "1\n2\n";
        return 0;
    }
    if (n == 4) {
        cout << "YES\n";
        cout << "1\n3\n2\n4\n";
        return 0;
    }

    if (primes(n).size() != 1) {
        cout << "NO\n";
        return 0;
    }

    int g = gen(n);
    cout << "YES\n";
    int s = 0;
    for (int i = 0; i < n / 2; ++i) {
        cout << Pow(g, i - s + (n - 1), n) << '\n';
        s = i;
        cout << Pow(g, (n - 2 - i) - s + (n - 1), n) << '\n';
        s = n - 2 - i;
    }
    cout << n << '\n';

}
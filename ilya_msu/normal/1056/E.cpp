#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>
#include <random>
#include <chrono>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> primes;
vector<int> c;

ll power(ll x, ll n, ll p) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % p;
        }
        x = (x * x) % p;
        n /= 2;
    }
    return res;
}

ll inv(ll x, ll p) {
    return power(x, p - 2, p);
}

void solve(const string& s, const string& t, ll p) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll x = uniform_int_distribution<int>(0, p)(rng) % p;
    ll invx = inv(x, p);
    vector<int> per(300);
    for (int i = 0; i < per.size(); ++i) {
        per[i] = i + 5;
    }
    shuffle(per.begin(), per.end(), rng);

    vector<ll> a(t.size() + 1);
    a[0] = 0;
    for (int i = 1; i <= t.size(); ++i) {
        a[i] = (a[i - 1] * x + per[(t[i - 1] - 'a')]) % p;
    }
    ll x0 = count(s.begin(), s.end(), '0');
    ll x1 = count(s.begin(), s.end(), '1');
    int i0 = s.size(), i1 = s.size();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0')
            i0 = min(i0, i);
        if (s[i] == '1')
            i1 = min(i1, i);
    }
    vector<ll> powers(t.size() + 1);
    powers[0] = 1;
    for (int i = 1; i < powers.size(); ++i) {
        powers[i] = (powers[i - 1] * x) % p;
    }
    for (ll l0 = 1; l0 * x0 < t.size(); ++l0) {
        ll l1 = (t.size() - l0 * x0) / x1;
        if (l0 * x0 + l1 * x1 != t.size())
            continue;
        ll h0 = (a[i0 * l1 + l0] - ((a[i0 * l1] * powers[l0]) % p) + p) % p;
        ll h1 = (a[i1 * l0 + l1] - ((a[i1 * l0] * powers[l1]) % p) + p) % p;
        //cerr << l0 << " " << l1 << " " << h0 << " " << h1 << endl;
        if ((h0 == h1) && (l0 == l1))
            continue;
        ll l = 0;
        bool ok = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                ll h = (a[l + l0] - ((a[l] * powers[l0]) % p) + p) % p;
                if (h != h0) {
                    ok = 0;
                    break;
                }
                l += l0;
            }
            else {
                ll h = (a[l + l1] - ((a[l] * powers[l1]) % p) + p) % p;
                if (h != h1) {
                    ok = 0;
                    break;
                }
                l += l1;
            }
        }
        if (ok)
            c[l0]++;
    }
}

void solve() {
    
    primes.push_back(1000000007);
    primes.push_back(1000000009);
    primes.push_back(1000000021);
    c.assign(1000000 + 10, 0);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < primes.size(); ++i)
        solve(s, t, primes[i]);
    cout << count(c.begin(), c.end(), primes.size()) << endl;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}
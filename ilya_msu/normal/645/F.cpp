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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1000005;
//const int M = 10000000;

vector<ll> phi(N);
vector<vector<int> > divisors(N);
vector<ll> fact(N);

ll power(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

ll inv(ll x) {
    return power(x, mod - 2);
}

vector<ll> cho(200000 + 10, -1);

ll choose(ll n, ll k) {
    if (n < k)
        return 0;
    if (cho[n] == -1)
        cho[n] = (((fact[n] * inv(fact[k])) % mod) * inv(fact[n - k])) % mod;
    return cho[n];
}

void precalc() {
    for (int i = 0; i < N; ++i)
        phi[i] = i;
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
    for (int i = 2; i < N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = (fact[i - 1] * i) % mod;

}



void solve() {
    precalc();
    int n, k, q;
    cin >> n >> k >> q;
    int x;
    vector<int> a(N, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        for (int j = 0; j < divisors[x].size(); ++j)
            ++a[divisors[x][j]];
    }
    ll sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        sum = sum + choose(a[i], k) * phi[i];
        sum %= mod;
    }
    for (int qq = 0; qq < q; ++qq) {
        cin >> x;
        for (int i = 0; i < divisors[x].size(); ++i) {
            int d = divisors[x][i];
            sum = sum + mod * phi[d] + choose(a[d] + 1, k) * phi[d] - choose(a[d], k) * phi[d];
            ++a[d];
            sum %= mod;
        }
        cout << sum << endl;
    }
    

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
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
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


vector<ll> factor(1000 + 10);

void init() {
    factor[0] = 1;
    for (int i = 1; i < factor.size(); ++i)
        factor[i] = (factor[i - 1] * i) % mod;
}

ll power(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return power(x, mod - 2);
}

ll choose(int n, int k) {
    if ((k < 0) || (k > n))
        return 0;
    return (factor[n] * inv((factor[k] * factor[n - k]) % mod)) % mod;
}


bool isOnes(string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != '1')
            return 0;
    }
    return 1;
}

int cnt(int x) {
    int res = 0;
    while (x) {
        if (x & 1)
            ++res;
        x /= 2;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    vector<int> a(1001, 0);
    a[1] = 1;
    for (int i = 1; i < k; ++i) {
        vector<int> b(1001, 0);
        for (int j = 2; j < b.size(); ++j) {
            int c = cnt(j);
            if (a[c])
                b[j] = 1;
        }
        swap(a, b);
    }
    int l = s.size();
    ll res = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0)
            continue;
        if (i > l)
            break;
        if (i == l) {
            res += isOnes(s);
            break;
        }
        int o = i;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') {
                res += choose(l - j - 1, o);
                --o;
            }
        }
        if (o == 0)
            ++res;
        res %= mod;
    }
    if (k == 1)
        --res;
    cout << res << endl;

    
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
    init();
	solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}
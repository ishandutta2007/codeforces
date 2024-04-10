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
#include<unordered_map>
#include<deque>
#include<cmath>
//#include<atcoder/dsu>


//using namespace atcoder;
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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


vector<string> get(ll x, ll a) {
    vector<int> b;
    while (a) {
        b.push_back(a & 1);
        a /= 2;
    }
    vector<string> res;
    int n = b.size();
    vector<ll> d(n);
    d[0] = x;
    for (int i = 1; i < n; ++i) {
        d[i] = d[i - 1] * 2;
        res.push_back(to_string(d[i - 1]) + " + " + to_string(d[i - 1]));
    }
    ll z = d[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (b[i]) {
            res.push_back(to_string(z) + " + " + to_string(d[i]));
            z += d[i];
        }
    }
    return res;
}

void solve() {
    ll x;
    cin >> x;
    ll dd = 0;
    for (ll d = 1; d < 20; ++d) {
        ll y = x << d;
        ll z = x ^ y;
        ll g = gcd(x, z);
        if (g == 1) {
            dd = d;
            break;
        }
    }
    vector<string> res;
    ll xx = x;
    for (int i = 0; i < dd; ++i) {
        res.push_back(to_string(xx) + " + " + to_string(xx));
        xx *= 2;
    }
    res.push_back(to_string(xx) + " ^ " + to_string(x));
    ll y = x << dd;
    ll z = x ^ y;
    res.push_back(to_string(z) + " + " + to_string(z));
    z = 2 * z;
    ll b = 1;
    while (((b * z) % x) != (x - 1))
        ++b;
    ll a = b * z / x + 1;
    vector<string> res1 = get(x, a), res2 = get(z, b);
    cout << res.size() + res1.size() + res2.size() + 1 << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << "\n";
    for (int i = 0; i < res1.size(); ++i)
        cout << res1[i] << "\n";
    for (int i = 0; i < res2.size(); ++i)
        cout << res2[i] << "\n";
    cout << a * x << " ^ " << b * z << endl;

    




    
}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
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
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
const int N = 1000000;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = gcd(b, a % b, x, y);
    ll q = a / b;
    ll xx = y;
    y = x - q * y;
    x = xx;
    return d;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    c = -c;
    ll d = gcd(gcd(abs(a), abs(b)), abs(c));
    a /= d, b /= d, c /= d;
    if ((a < 0) || ((a == 0) && (b < 0)))
        a = -a, b = -b, c = -c;
    ll x, y;
    d = gcd(a, abs(b), x, y);
    if (c % d != 0) {
        cout << -1 << endl;
        return;
    }
    if (b < 0)
        y = -y;
    cout << x * (c / d) << " " << y * (c / d) << endl;    
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
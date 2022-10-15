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
const ll N = 10000;
//const int M = 10000000;



void solve() {
    ll c, h1, h2, w1, w2;
    cin >> c >> h1 >> h2 >> w1 >> w2;
    if (h1 * w2 >= h2 * w1)
        swap(h1, h2), swap(w1, w2);
    ll res = 0;
    if (w2 < N) {
        for (ll x = 0; (x < w2) && (x * w1 <= c); ++x) {
            ll y = (c - x * w1) / w2;
            res = max(res, x * h1 + y * h2);
        }
    }
    else {
        for (ll y = 0; y * w2 <= c; ++y) {
            ll x = (c - y * w2) / w1;
            res = max(res, x * h1 + y * h2);
        }
    }
    cout << res << endl;


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
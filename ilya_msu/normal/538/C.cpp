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

int get(int d, int h1, int h2) {
    if (h1 < h2)
        swap(h1, h2);
    d -= h1 - h2;
    return h1 + d / 2;

}

void solve() {
    int n, m;
    cin >> n >> m;
    int h = 0, d = 0;
    cin >> d >> h;
    int res = h + d - 1;
    bool ok = true;
    for (int i = 1; i < m; ++i) {
        int hh, dd;
        cin >> dd >> hh;
        if (abs(hh - h) > dd - d)
            ok = false;
        int cur = get(dd - d, h, hh);
        d = dd;
        h = hh;
        res = max(res, cur);
    }
    res = max(res, h + n - d);
    if (ok)
        cout << res << endl;
    else
        cout << "IMPOSSIBLE" << endl;


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
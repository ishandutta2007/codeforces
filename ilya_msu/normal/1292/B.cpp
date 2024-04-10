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
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    ll N = (ll)20 * 1000 * 1000 * 1000 * 1000 * 1000;
    vector<ll> x, y;
    ll ax, ay, bx, by;
    ll x0, y0, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    x.push_back(x0);
    y.push_back(y0);
    while (true) {
        ll xx = x[x.size() - 1];
        ll yy = y[y.size() - 1];
        if ((xx > N) || (yy > N))
            break;
        xx = xx * ax + bx;
        yy = yy * ay + by;
        x.push_back(xx);
        y.push_back(yy);
    }
    int res = 0;
    for (int i1 = 0; i1 < x.size(); ++i1) {
        for (int i2 = i1 + 1; i2 <= x.size(); ++i2) {
            ll c1 = abs(xs - x[i1]) + x[i2 - 1] - x[i1] + y[i2 - 1] - y[i1] + abs(ys - y[i1]);
            ll c2 = abs(xs - x[i2 - 1]) + x[i2 - 1] - x[i1] + y[i2 - 1] - y[i1] + 
            abs(ys - y[i2 - 1]);
            if (min(c1, c2) <= t)
                res = max(res, i2 - i1);
        }
    }
    cout << res << endl;

}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}
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


double dist(pdd a, pdd b) {
    return sqrt(fabs(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)));
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((a == 0) || (b == 0)) {
        ll res = abs(x1 - x2) + abs(y1 - y2);
        cout << res << endl;
        return;
    }
    vector<pdd> v(2), u(2);
    v[0] = make_pair(x1, 1.0 * (-c - a * x1) / b);
    v[1] = make_pair(1.0 * (-c - b * y1) / a, y1);
    u[0] = make_pair(x2, 1.0 * (-c - a * x2) / b);
    u[1] = make_pair(1.0 * (-c - b * y2) / a, y2);
    double res = fabs(x1 - x2) + fabs(y1 - y2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            res = min(res, dist(v[i], u[j]) + dist(v[i], pdd(x1, y1)) + dist(u[j], pdd(x2, y2)));

        }
    }
    printf("%0.18f\n", res);

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
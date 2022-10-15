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





void solve() {
    int a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    if ((v < w) || (0.5 * w * w / a > d)) {
        double t1 = v * 1.0 / a;
        if (a * t1 * t1 * 0.5 > l) {
            double t = sqrt(2.0 * l / a);
            printf("%0.18f\n", t);
            return;
        }
        double t2 = (l - a * t1 * t1 * 0.5) / v;
        printf("%0.18f\n", t1 + t2);
        return;
    }
    double t1 = v * 1.0 / a;
    double t2 = (v - w) * 1.0 / a;
    if (t1 * t1 * a * 0.5 + t2 * (v + w) * 0.5 < d) {
        double t3 = (d - t1 * t1 * a / 2 - t2 * (v + w) / 2) / v;
        if (t2 * (v + w) / 2 < l - d) {
            double t4 = (l - d - t2 * (v + w) / 2) / v;
            printf("%0.18f\n", t1 + 2 * t2 + t3 + t4);
            return;
        }
        double t4 = (sqrt(w * w + 2.0 * a * (l - d)) - w) / a;
        printf("%0.18f\n", t1 + t2 + t3 + t4);
        return;
    }
    t1 = sqrt((2.0 * a * d + w * w) * 0.5) / a;
    t2 = t1 - w * 1.0 / a;
    double t3 = (v - w) * 1.0 / a;
    if (t3 * (v + w) / 2 < l - d) {
        double t4 = (l - d - t3 * (v + w) / 2) / v;
        printf("%0.18f\n", t1 + t2 + t3 + t4);
        return;
    }
    double t4 = (sqrt(w * w + 2.0 * a * (l - d)) - w) / a;
    printf("%0.18f\n", t1 + t2 + t4);
    return;
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
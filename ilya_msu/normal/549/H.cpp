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


void solve() {
    vector<ll> a(4);
    for (int i = 0; i < 4; ++i)
        cin >> a[i];
    if (a[0] * a[3] == a[1] * a[2]) {
        cout << 0 << endl;
        return;
    }
    long double down = 0, up = abs(a[0]) + abs(a[1]) + abs(a[2]) + abs(a[3]);
    for (int i = 0; i < 1000; ++i) {
        long double mid = (up + down) / 2;
        bool ok = false;
        vector<long double> b1(4), b2(4);
        for (int j = 0; j < 4; ++j) {
            b1[j] = a[j] - mid;
            b2[j] = a[j] + mid;
        }
        vector<long double> c(4);
        bool pos = 0;
        for (int m = 0; m < 16; ++m) {
            for (int j = 0; j < 4; ++j) {
                if ((m >> j) & 1)
                    c[j] = b1[j];
                else
                    c[j] = b2[j];
            }
            long double d1 = c[0] * c[3], d2 = c[1] * c[2];
            if (m == 0)
                pos = (d1 > d2);
            else {
                if (pos != (d1 > d2))
                    ok = 1;
            }
        }
        if (ok)
            up = mid;
        else
            down = mid;
    }
    printf("%0.18f\n", up);
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
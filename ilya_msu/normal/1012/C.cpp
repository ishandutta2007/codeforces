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




void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m = (n + 1) / 2;
    vector<vector<ll> > d1(m + 1, vector<ll> (3, INF));
    vector<vector<ll> > d2;

    d1[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        d2.assign(m + 1, vector<ll> (3, INF));
        for (int k = 0; k <= m; ++k) {
            d2[k][0] = min(d2[k][0], d1[k][0]);
            int c = 0;
            if (i > 0)
                c = max(0, a[i - 1] - a[i] + 1);
            if (k < m) {
                d2[k + 1][1] = min(d2[k + 1][1], d1[k][0] + c);
            }
            int c1 = 0;
            if (i > 0)
                c1 = max(0, a[i] - a[i - 1] + 1);
            d2[k][2] = min(d2[k][2], d1[k][1] + c1);
            d2[k][0] = min(d2[k][0], d1[k][2]);
            int c2 = 0;
            if (i >= 2) {
                c2 = max(0, min(a[i - 1], a[i - 2] - 1) - a[i] + 1);
            }
            if (k < m) {
                d2[k + 1][1] = min(d2[k + 1][1], d1[k][2] + c2);
            }
        }
        swap(d1, d2);
    }
    for (int k = 1; k <= m; ++k) {
        cout << min(d1[k][0], min(d1[k][1], d1[k][2])) << " ";

    }
    cout << endl;
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
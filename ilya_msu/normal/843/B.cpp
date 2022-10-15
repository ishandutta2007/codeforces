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
    int n, st, x;
    cin >> n >> st >> x;
    int stage1 = 999;
    cout << "? " << st << endl;
    fflush(stdout);
    int v1, nxt1;
    cin >> v1 >> nxt1;
    if (v1 >= x) {
        cout << "! " << v1 << endl;
        fflush(stdout);
        return;
    }
    int v2 = INF, en = -1;
    for (int i = 0; i < stage1; ++i) {
        int r = (rand() * RAND_MAX + rand()) % n + 1;
        cout << "? " << r << endl;
        fflush(stdout);
        int v, nxt;
        cin >> v >> nxt;
        if (v < x) {
            if (v1 < v) {
                st = r;
                v1 = v;
            }
        }
        else {
            if (v2 > v) {
                v2 = v;
                en = r;
            }
        }
    }
    cerr << v1 << " " << v2 << endl;
    int cur = st;
    int res = v1;
    while (cur != en) {
        cout << "? " << cur << endl;
        fflush(stdout);
        int v, nxt;
        cin >> v >> nxt;
        if (v >= x) {
            cout << "! " << v << endl;
            fflush(stdout);
            return;
        }
        cur = nxt;
    }
    if (v2 == INF)
        cout << "! " << -1 << endl;
    else
        cout << "! " << v2 << endl;

    fflush(stdout);
}



//#define LOCAL

int main() {
    srand(time(NULL));
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
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
const ll mod = 998244353;


void solve() {
    int n;
    cin >> n;
    vector<vector<ll> > a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i) {
        int m = 2 * n - 1 - i;
        a[i].assign(m, i);
        ll x = 1;
        for (int j = m - 2; j >= 0; --j) {
            a[i][j] = x * i;
            x *= 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    for (int qq = 0; qq < q; ++qq) {
        ll m;
        cin >> m;
        ll x = 0, y = 0;
        cout << x + 1 << " " << y + 1 << endl;
        for (int i = 0; i < 2 * n - 2; ++i) {
            if ((m >> (2 * n - 2 - i - 1)) & 1) {
                ++x;
            }
            else 
                ++y;
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
    /*for (ll m = 0; m < 100000; ++m) {
        ll res = a[0][0];
        ll x = 0, y = 0;
        for (int i = 0; i < 2 * n - 2; ++i) {
            if ((m >> (2 * n - 2 - i - 1)) & 1) {
                ++x;
            }
            else 
                ++y;
            res += a[x][y];
        }
        if (m != res)
            cout << "AHUF\n";
    }*/
    

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
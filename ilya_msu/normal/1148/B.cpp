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
const ll mod = 998244353;



void solve() {
    ll n, m, t1, t2, k;
    cin >> n >> m >> t1 >> t2 >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += t1 + t2;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        b[i] += t2;
    }
    int i1 = 0, i2 = 0;
    int sh = 0;
    while ((i1 < n) || (i2 < m)) {
        if (i1 == n) {
            ++i2;
        } else 
        if (i2 == m) {
            ++i1;
        }
        else {
            if (a[i1] <= b[i2]) {
                ++i1;
            }
            else {
                ++i2;
            }
        }
        sh = max(sh, i2 - i1);
        int x = i2 - sh;
        if (x > k) {
            cout << b[i2 - 1] << endl;
            return;
        }
    }
    cout << -1 << endl;
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
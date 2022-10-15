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
    int n, q;
    int N = 200000 + 10;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> right(N, -1);
    vector<int> c(N, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        right[a[i]] = i;
        ++c[a[i]];
    }
    int r = 0;
    int res = n;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        r = max(r, right[a[i]]);
        m = max(m, c[a[i]]);
        //cerr << r << endl;
        if (r == i) {
            res -= m;
            m = 0;
        }
    }
    cout << res << endl;
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
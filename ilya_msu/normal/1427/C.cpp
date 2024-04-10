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
//#include<atcoder/dsu>


//using namespace atcoder;
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
    int r, n;
    cin >> r >> n;
    int N = 1000;
    vector<int> x(n + 1, 0), y(n + 1, 0), t(n + 1, 0), d(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
        --x[i + 1];
        --y[i + 1];
    }
    int mx = -1;
    int res = 0;
    for (int i = 1; i < n + 1; ++i) {
        if (i >= N)
            mx = max(mx, d[i - N]);
        d[i] = mx + 1;
        for (int j = max(0, i - N + 1); j < i; ++j) {
            if ((abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) && 
            ((d[j] > 0) || (j == 0))) {
                d[i] = max(d[i], d[j] + 1);
                //cerr << j << " " << i << " " << d[i] << endl;
            }
        }
        res = max(res, d[i]);
        //cerr << d[i] << endl;
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
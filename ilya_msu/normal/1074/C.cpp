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

int solve(const vector<int>& x, const vector<int>& y) {
    int mx1, mx2, my1, my2;
    mx1 = mx2 = my1 = my2 = INF;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] < mx1) {
            //mx2 = mx1;
            mx1 = x[i];
            continue;
        }
        
    }
    for (int i = 0; i < x.size(); ++i) {
        if (y[i] < my1) {
            //my2 = my1;
            my1 = y[i];
            continue;
        }
        
    }
    int res = 0;
    for (int i = 0; i < x.size(); ++i) {
        int xx = x[i] - mx1, yy = y[i] - my1;
        //if ((xx == 0) || (yy == 0))
        //    continue;
        res = max(res, xx + yy);
    }
    return res * 2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    int res = solve(x, y);
    for (int i = 0; i < n; ++i) {
        x[i] = -x[i];
    }
    res = max(res, solve(x, y));
    for (int i = 0; i < n; ++i) {
        y[i] = -y[i];
    }
    res = max(res, solve(x, y));
    for (int i = 0; i < n; ++i) {
        x[i] = -x[i];
    }
    res = max(res, solve(x, y));
    cout << res;
    int mx1 = x[0], mx2 = x[0], my1 = y[0], my2 = y[0];
    for (int i = 0; i < n; ++i) {
        mx1 = max(mx1, x[i]);
        mx2 = min(mx2, x[i]);
        my1 = max(my1, y[i]);
        my2 = min(my2, y[i]);
    }
    res = 2 * (mx1 - mx2 + my1 - my2);
    for (int i = 4; i <= n; ++i) 
        cout << " " << res;
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
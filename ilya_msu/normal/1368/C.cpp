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
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    int n;
    cin >> n;
    vector<int> x, y;
    x.push_back(0);
    y.push_back(0);
    int xx = 0, yy = 0;
    for (int i = 0; i < n + 1; ++i) {
        x.push_back(xx);
        x.push_back(xx);
        y.push_back(yy + 1);
        y.push_back(yy + 2);

        x.push_back(xx + 1);
        x.push_back(xx + 2);
        y.push_back(yy);
        y.push_back(yy);

        x.push_back(xx + 1);
        y.push_back(yy + 2);
        x.push_back(xx + 2);
        y.push_back(yy + 1);

        x.push_back(xx + 2);
        y.push_back(yy + 2);

        xx += 2;
        yy += 2;
    }

    cout << x.size() << "\n";
    for (int i = 0; i < x.size(); ++i) {
        cout << x[i] << " " << y[i] << "\n";
    }

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
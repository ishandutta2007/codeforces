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
    vector<pii> p(3);
    for (int i = 0; i < 3; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    vector<int> x(3), y(3);
    for (int i = 0; i < 3; ++i) {
        x[i] = p[i].first;
        y[i] = p[i].second;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int a = x[1], b = y[1];
    vector<pii> res;
    res.push_back(pii(a, b));
    for (int i = 0; i < 3; ++i) {
        int x1 = p[i].first, y1 = p[i].second;
        while (x1 != a) {
            res.push_back(pii(x1, y1));
            if (x1 < a) 
                ++x1;
            else
                --x1;
        }
        while (y1 != b) {
            res.push_back(pii(x1, y1));
            if (y1 < b) 
                ++y1;
            else
                --y1;
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first << " " << res[i].second << "\n";
    }

    

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
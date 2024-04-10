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

int N = 1000000;

void solve() {
    vector<vector<int> > div(N + 1);
    for (int i = 2; i < div.size(); ++i) {
        if (div[i].empty()) {
            for (int j = i; j < div.size(); j += i) {
                div[j].push_back(i);
            }
        }
    }
    int x2;
    cin >> x2;
    int minx1 = x2;
    for (int i = 0; i < div[x2].size(); ++i) {
        int p = div[x2][i];
        minx1 = min(minx1, max(p + 1, x2 - p + 1));
    }
    int res = x2;
    for (int x1 = minx1; x1 <= x2; ++x1) {
        for (int j = 0; j < div[x1].size(); ++j) {
            int p = div[x1][j];
            res = max(3, min(res, max(p + 1, x1 - p + 1)));
        }
    }
    cout << res << endl;

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
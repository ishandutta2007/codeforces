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

int pr(int x) {
    int res = 1;
    while (x) {
        int r = x % 10;
        x /= 10;
        if (r)
            res *= r;
    }
    return res;
}

void solve() {
    vector<int> g(1000000 + 10);
    for (int i = 1; i < 10; ++i)
        g[i] = i;
    for (int i = 10; i < g.size(); ++i) {
        g[i] = g[pr(i)];
    }
    vector<vector<int> > a(10);
    for (int i = 1; i < g.size(); ++i) {
        a[g[i]].push_back(i);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << upper_bound(a[k].begin(), a[k].end(), r) - lower_bound(a[k].begin(), a[k].end(), l) << "\n";
    }
}

//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
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
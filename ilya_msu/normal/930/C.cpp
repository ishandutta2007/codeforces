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


struct SegTree {
    const int MINUS_INF = numeric_limits<int>::min();
    int n;
    vector<int> t;
    SegTree(int nn) {
        n = nn;
        t.assign(4 * n + 10, 0);
    }
    int getMax(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return MINUS_INF;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return max(getMax(v * 2, tl, tm, l, min(r, tm)), getMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    int getMax(int l, int r) {
        return getMax(1, 0, n - 1, l, r);
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int pos, int new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        ++c[a], --c[b];
    }
    for (int i = 1; i < c.size(); ++i)
        c[i] += c[i - 1];
    vector<int> d1(m, 1), d2(m, 1);
    SegTree t1(n + 1), t2(n + 1);
    t1.update(c[0], 1);
    t2.update(c[m - 1], 1);
    for (int i = 1; i < m; ++i) {
        d1[i] = t1.getMax(0, c[i]) + 1;
        t1.update(c[i], d1[i]);
    }
    for (int i = m - 2; i >= 0; --i) {
        d2[i] = t2.getMax(0, c[i]) + 1;
        t2.update(c[i], d2[i]);
    }
    int res = 0;
    for (int i = 0; i < m; ++i)
        res = max(res, d1[i] + d2[i] - 1);
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
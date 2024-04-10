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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;

struct SegTree {
    int n;
    vector<int> a, c;

    void build(int v, int l, int r, const vector<int>& b) {
        if (l == r) {
            a[v] = b[l];
            c[v] = b[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, b);
        build(2 * v + 1, m + 1, r, b);
        a[v] = min(a[2 * v], a[2 * v + 1]);
        c[v] = max(c[2 * v], c[2 * v + 1]);

    }
    SegTree(const vector<int>& b) {
        n = b.size();
        a.resize(4 * n + 10);
        c.resize(4 * n + 10);
        build(1, 0, b.size() - 1, b);
    }
    int getMin(int v, int tl, int tr, int l, int r) {
        if ((tl >= l) && (tr <= r))
            return a[v];
        if ((tl > r) || (tr < l))
            return INF;
        int m = (tl + tr) / 2;
        return min(getMin(2 * v, tl, m, l, r), getMin(2 * v + 1, m + 1, tr, l, r));
    }
    int getMax(int l, int r) {
        return getMax(1, 0, n - 1, l, r);
    }
    int getMax(int v, int tl, int tr, int l, int r) {
        if ((tl >= l) && (tr <= r))
            return c[v];
        if ((tl > r) || (tr < l))
            return -INF;
        int m = (tl + tr) / 2;
        return max(getMax(2 * v, tl, m, l, r), getMax(2 * v + 1, m + 1, tr, l, r));
    }
    int getMin(int l, int r) {
        return getMin(1, 0, n - 1, l, r);
    }
};

void solve() {
    vector<string> a(8);
    for (int i = 0; i < 8; ++i)
        cin >> a[i];
    int x = 0, y = 0;
    for (int i = 0; i < 8; ++i) {
        bool ok = 1;
        for (int j = 0; j < 8; ++j) {
            if (a[i][j] != 'B')
                ok = 0;
        }
        if (ok)
            ++x;
        ok = 1;
        for (int j = 0; j < 8; ++j) {
            if (a[j][i] == 'W')
                ok = 0;
        }
        if (ok)
            ++y;
    }
    int res = x + y;
    if (res == 16)
        res = 8;
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
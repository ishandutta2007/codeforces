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
//#include<unordered_map>




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

int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

struct SegTree {
    int n;
    vector<int> t;
    SegTree(int nn) {
        n = nn;
        t.assign(4 * n + 10, 0);
    }
    SegTree(const vector<int>& a) {
        n = a.size();
        t.assign(4 * n + 10, 0);
        build(1, 0, n - 1, a);
    }
    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm + 1, tr, a);
        t[v] = gcd(t[2 * v], t[2 * v + 1]);
        return;
    }

    int getRes01(int v, int tl, int tr, int l, int r, int x) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            if ((t[v] % x) == 0)
                return 0;
            return 1;
        }
        int tm = (tl + tr) / 2;
        int res = getRes01(v * 2, tl, tm, l, min(r, tm), x);
        if (res < 1)
            res += getRes01(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        return res;
    }
    int getRes(int v, int tl, int tr, int l, int r, int x) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            if ((t[v] % x) == 0)
                return 0;
            if (tr == tl)
                return 1;
            int tm = (tl + tr) / 2;
            if ((t[2 * v + 1] % x) == 0)
                return getRes(v * 2, tl, tm, l, min(r, tm), x);
            if ((t[2 * v] % x) == 0)
                return getRes(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
            return 2;
        }
        int tm = (tl + tr) / 2;
        int res = getRes(v * 2, tl, tm, l, min(r, tm), x);
        if (res >= 2)
            return 2;
        if (res == 1) 
            return 1 + getRes01(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        return getRes(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    }
    
    int getRes(int l, int r, int x) {
        int res = getRes(1, 0, n - 1, l, r, x);
        return res;
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
            t[v] = gcd(t[v * 2], t[v * 2 + 1]);
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    SegTree tr(a);
    /*for (int i = 0; i < n; ++i)
        tr.update(1, 0, n - 1, i, a[i]);*/
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            int res = tr.getRes(l, r, x);
            if (res <= 1) {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        else {
            int id, y;
            cin >> id >> y;
            tr.update(1, 0, n - 1, id - 1, y);
        }
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
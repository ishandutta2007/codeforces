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
    SegTree(int nn = 0) {
        n = nn;
        t.assign(4 * n + 10, 0);
    }
    int build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr)
            return t[v] = a[tl];
        int mid = (tl + tr) / 2;
        return t[v] = max(build(2 * v, tl, mid, a), build(2 * v + 1, mid + 1, tr, a));
    }
    void build(const vector<int>& in) {
        build(1, 0, n - 1, in);
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pii> qu(q + 1, pii(n, -1));
    int pos0 = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            pos0 = i;
            a[i] = -q-1;
            continue;
        }
        qu[a[i]].first = min(qu[a[i]].first, i);
        qu[a[i]].second = max(qu[a[i]].second, i);
        a[i] = -a[i];
    }
    SegTree tr(n);
    tr.build(a);
    bool ok = 1;
    for (int i = 1; i <= q; ++i) {
        if (qu[i].first > qu[i].second)
            continue;
        int res = tr.getMax(qu[i].first, qu[i].second);
        if (-res < i) {
            ok = 0;
            break;
        }
    }
    if (qu[q].first > qu[q].second) {
        if (pos0 == -1) {
            ok = 0;
        }
        else {
            a[pos0] = -q;
        }
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -q-1) {
            a[i] = 0;
        }
        if (a[i] < 0) {
            a[i] = -a[i];
            pos = i;
        }
    }
    if (pos == -1) {
        pos = 0;
        a[0] = q;
    }
    for (int i = pos; i < n; ++i) {
        if (a[i] == 0) {
            a[i] = a[i - 1];
        }
    }
    for (int i = pos; i >= 0; --i) {
        if (a[i] == 0) {
            a[i] = a[i + 1];
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
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
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
const ll mod = 998244353;

struct SegTree {
    const int MINUS_INF = numeric_limits<int>::min();
    int n;
    vector<ll> t;
    vector<ll> add;
    SegTree(int nn = 0) {
        n = nn;
        t.assign(4 * n + 10, 0);
        add.assign(4 * n + 10, 0);
    }
    int build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            t[v] = a[tl];
            return t[v];
        }
        int mid = (tl + tr) / 2;
        t[v] = max(build(2 * v, tl, mid, a), build(2 * v + 1, mid + 1, tr, a));
        return t[v];
    }
    void build(const vector<int>& in) {
        build(1, 0, n - 1, in);
    }
    int get(int v, int tl, int tr) {
        if (t[v] + add[v] <= 0)
            return -1;
        if (tl == tr)
            return tl;
        add[2 * v] += add[v];
        add[2 * v + 1] += add[v];
        t[v] += add[v];
        add[v] = 0;
        int tm = (tl + tr) / 2;
        if (t[2 * v + 1] + add[2 * v + 1] > 0) 
            return get(2 * v + 1, tm + 1, tr);
        return get(2 * v, tl, tm);
    }
    int get() {
        return get(1, 0, n - 1);
    }
    void update(int v, int tl, int tr, int posl, int posr, int addv) {
        if (posl > posr)
            return;
        if ((tl == posl) && (tr == posr)) {
            add[v] += addv;
            return;
        }
        else {
            int tm = (tl + tr) / 2;
            add[2 * v] += add[v];
            add[2 * v + 1] += add[v];
            add[v] = 0;
            update(v * 2, tl, tm, posl, min(posr, tm), addv);
            update(v * 2 + 1, tm + 1, tr, max(posl, tm + 1), posr, addv);
            t[v] = max(t[v * 2] + add[2 * v], t[v * 2 + 1] + add[2 * v + 1]);
        }
    }
    void update(int posl, int posr, int addv) {
        update(1, 0, n - 1, posl, posr, addv);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int N = 1000 * 1000 + 10;
    vector<int> sum(N);
    for (int i = 0; i < n; ++i) {
        ++sum[a[i]];
    }
    for (int i = 0; i < m; ++i) {
        --sum[b[i]];
    }
    for (int i = sum.size() - 2; i >= 0; --i) {
        sum[i] += sum[i + 1];
    }
    //cerr << "precalc\n";
    SegTree tr(N);
    tr.build(sum);
    int q;
    cin >> q;
    int t, id, x;
    for (int i = 0; i < q; ++i) {
        //cerr << i << "\n";
        cin >> t >> id >> x;
        if (t == 1) {
            int x1 = a[id - 1];
            int x2 = x;
            if (x2 > x1) {
                tr.update(x1 + 1, x2, 1);
            }
            if (x2 < x1) {
                tr.update(x2 + 1, x1, -1);
            }
            a[id - 1] = x;
        }
        else {
            int x1 = b[id - 1];
            int x2 = x;
            if (x2 > x1) {
                tr.update(x1 + 1, x2, -1);
            }
            if (x2 < x1) {
                tr.update(x2 + 1, x1, 1);
            }
            b[id - 1] = x;
        }
        int r = tr.get();
        cout << r << "\n";
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
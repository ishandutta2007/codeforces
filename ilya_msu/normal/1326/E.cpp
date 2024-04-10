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
const ll N = 100000 + 10;


struct SegTreeWithAdd {
    const int MINUS_INF = numeric_limits<int>::min();
    int n;
    vector<ll> t;
    vector<ll> add;
    SegTreeWithAdd(int nn = 0) {
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
        n = in.size();
        t.assign(4 * n + 10, 0);
        add.assign(4 * n + 10, 0);
        build(1, 0, n - 1, in);
    }
    int getMax(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return MINUS_INF;
        if (l == tl && r == tr)
            return t[v] + add[v];
        int tm = (tl + tr) / 2;
        add[2 * v] += add[v];
        add[2 * v + 1] += add[v];
        t[v] += add[v];
        add[v] = 0;
        return max(getMax(v * 2, tl, tm, l, min(r, tm)), getMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    int getMax(int l, int r) {
        return getMax(1, 0, n - 1, l, r);
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
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
            add[v] = 0;
        }
        else {
            add[2 * v] += add[v];
            add[2 * v + 1] += add[v];
            add[v] = 0;
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = max(t[v * 2] + add[2 * v], t[v * 2 + 1] + add[2 * v + 1]);
        }
    }
    void update(int pos, int new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        --q[i];
    }
    vector<int> rp(n);
    for (int i = 0; i < n; ++i) {
        rp[p[i]] = i;
    }
    SegTreeWithAdd tr(n + 1);
    int qid = 0;
    for (int i = 0; i < n; ++i) {
        tr.update(0, rp[n - 1 - i], 1);
        while (tr.getMax(0, n) > 0) {
            tr.update(0, q[qid], -1);
            ++qid;
            cout << n - i << " ";
        }
    }
    cout << endl;

    

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
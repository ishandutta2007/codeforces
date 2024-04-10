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

class ev {
    public:
    ll t;
    ll type;
    ll id;
    ev(ll a, ll b, ll c) : t(a), type(b), id(c) {}
};

struct SegTree {
    const ll PLUS_INF = numeric_limits<ll>::max();
    int n;
    vector<pll> t;
    SegTree(int nn = 0) {
        n = nn;
        t.assign(4 * n + 10, pll(PLUS_INF, -1));
    }
    pll build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr)
            return t[v] = pll(a[tl], tl);
        int mid = (tl + tr) / 2;
        return t[v] = min(build(2 * v, tl, mid, a), build(2 * v + 1, mid + 1, tr, a));
    }
    void build(const vector<int>& in) {
        n = in.size();
        t.assign(4 * n + 10, pii(0, 0));
        build(1, 0, n - 1, in);
    }
    pll getMin(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return pll(PLUS_INF, -1);
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return min(getMin(v * 2, tl, tm, l, min(r, tm)), getMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    pll getMin(int l, int r) {
        return getMin(1, 0, n - 1, l, r);
    }
    void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            t[v] = pll(new_val, tl);
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int pos, ll new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
};


void solve() {
    ll n, p;
    cin >> n >> p;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<ll> res(n, 0);
    vector<pll> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = pll(t[i], i);
    }
    sort(a.begin(), a.end());
    vector<int> ord;
    ll T = a[0].first;
    priority_queue<int> active;
    int pt = 0;
    while ((pt < n) && (a[pt].first <= T)) {
        active.push(-a[pt].second);
        ++pt;
    }
    bool em = 1;
    SegTree tr(n);
    tr.build(t);
    while (true) {
        if (active.empty()) {
            if (pt == n)
                break;
            T = max(T, a[pt].first);
            
        }
        while ((pt < n) && (a[pt].first <= T)) {
            active.push(-a[pt].second);
            ++pt;
        }
        int id = -active.top();
        cerr << id << endl;
        active.pop();
        if (res[id] != 0)
            continue;
        res[id] = T + p;
        T += p;
        tr.update(id, LINF);
        int curId = id;
        while (true) {
            pll v = tr.getMin(0, curId - 1);
            if (v.first <= T) {
                curId = v.second;
                res[curId] = T + p;
                tr.update(curId, LINF);
                T += p;
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}
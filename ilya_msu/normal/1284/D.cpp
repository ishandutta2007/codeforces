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
        n = in.size();
        t.assign(4 * n + 10, 0);
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


bool check(vector<pair<pii, pii> > a) {
    int n = a.size();
    SegTree tr1;
    SegTree tr2;
    
    vector<int> lft(n);
    for (int i = 0; i < n; ++i)
        lft[i] = a[i].second.first;
    tr1.build(lft);
    vector<int> rt(n);
    for (int i = 0; i < n; ++i)
        rt[i] = -a[i].second.second;
    tr2.build(rt);
    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        d[i] = a[i].first.first;

    for (int i = 0; i < n; ++i) {
        int r = upper_bound(d.begin(), d.end(), a[i].first.second) - d.begin();
        int lm = tr1.getMax(i, r - 1);
        if (lm > a[i].second.second)
            return 0;
        int rm = -tr2.getMax(i, r - 1);
        if (rm < a[i].second.first)
            return 0;
    }
    return 1;
}


void solve() {
    int n;
    cin >> n;
    vector<pair<pii, pii> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
    }
    vector<pair<pii, pii> > b(a);
    for (int i = 0; i < n; ++i) {
        swap(b[i].first, b[i].second);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (check(a) && check(b))
        cout << "YES\n";
    else 
        cout << "NO\n";

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
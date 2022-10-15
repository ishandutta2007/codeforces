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
const int negINF = numeric_limits<int>::min();

const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

class SegTreeSum {
    int n;
    vector<long long> t;
    vector<long long> addToAll;

    long long getSum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v] + (r - l + 1) * addToAll[v];
        int tm = (tl + tr) / 2;
        addToAll[2 * v] += addToAll[v];
        addToAll[2 * v + 1] += addToAll[v];
        addToAll[v] = 0;
        return getSum(v * 2, tl, tm, l, min(r, tm)) + getSum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            t[v] = new_val;
            addToAll[v] = 0;
        }
        else {
            addToAll[2 * v] += addToAll[v];
            addToAll[2 * v + 1] += addToAll[v];
            addToAll[v] = 0;
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = getSum(v * 2, tl, tm, tl, tm) + getSum(v * 2 + 1, tm + 1, tr, tm + 1, tr);// t[v * 2] + t[v * 2 + 1];
        }
    }
    void update(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, a);
            update(v * 2 + 1, tm + 1, tr, a);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void addToSeg(int v, int tl, int tr, int l, int r, long long addVal) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            addToAll[v] += addVal;
            return;
        }
        int tm = (tl + tr) / 2;
        addToAll[2 * v] += addToAll[v];
        addToAll[2 * v + 1] += addToAll[v];
        addToAll[v] = 0;
        addToSeg(v * 2, tl, tm, l, min(r, tm), addVal);
        addToSeg(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addVal);
    }
public:
    void addToSeg(int l, int r, long long addVal) {
        addToSeg(1, 0, n - 1, l, r, addVal);
    }
    ll getSum(int l, int r) {
        return getSum(1, 0, n - 1, l, r);
    }
    void update(int pos, long long new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
    SegTreeSum(int nn) {
        n = nn;
        t.assign(4 * n + 10, 0);
        addToAll.assign(4 * n + 10, 0);
    }
    SegTreeSum(const vector<int>& a) {
        n = a.size();
        t.assign(4 * n + 10, 0);
        addToAll.assign(4 * n + 10, 0);
        update(1, 0, n - 1, a);
    }
};

bool comp(const pair<pll, pair<double, int> >& a, const pair<pll, pair<double, int> >& b) {
    ll r = a.first.first * b.first.second - a.first.second * b.first.first;
    if (r < 0)
        return 1;
    if (r > 0)
        return 0;
    return a.second < b.second;
}


vector<int> getPerm(vector<int> v, vector<int> x, int mod) {
    int n = v.size();
    vector<pair<pll, pair<double, int> > > a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = make_pair(pll(abs(x[i]), abs(v[i])), make_pair(abs(x[i] * 1.0 / (v[i] + 0.5 * mod)), i));
    }
    sort(a.begin(), a.end(), comp);
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = a[i].second.second;
    return res;
}


ll countInv(vector<int> a) {
    int n = a.size();
    SegTreeSum tr(n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += tr.getSum(a[i], n - 1);
        tr.update(a[i], 1);
    }
    return res;
}

ll countInv(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[a[i]] = i;
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = p[b[i]];
    }
    return countInv(c);
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> v(n), x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> v[i];
    }
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        v1[i] = v[i] + w;
        v2[i] = v[i] - w;
    }
    vector<int> p1 = getPerm(v1, x, 1);
    vector<int> p2 = getPerm(v2, x, -1);
    cout << countInv(p1, p2) << endl;
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
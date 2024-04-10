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
const ll mod = 1000000007;
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
    int getSum(int l, int r) {
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

void solve() {
    ll n;
    cin >> n;
    vector<ll> f(n, 0);
    vector<int> p(n), rp(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        rp[p[i]] = i;
    }
    SegTreeSum tr1(n);
    vector<ll> res1(n, 0);
    for (int i = 0; i < n; ++i) {
        //cerr << i << endl;
        res1[i] += tr1.getSum(rp[i], n - 1);
        tr1.update(rp[i], 1);
    }
    for (int i = 1; i < n; ++i) {
        res1[i] += res1[i - 1];
    }
    vector<ll> res2(n);
    set<int> st;
    ll add = 0;
    st.insert(rp[0]);
    int pos = 0;
    auto it = st.find(rp[0]);
    int med = rp[0];
    for (int i = 1; i < n; ++i) {
        st.insert(rp[i]);
        if (rp[i] < med) {
            ++pos;
        }
        add += abs(med - rp[i]);
        int npos = i / 2;
        int nmed = med;
        //cerr << i << " " << pos << " " << npos << endl;
        if (pos == npos) {
            res2[i] = add;
            continue;
        }
        it = st.find(med);
        if (pos < npos) {
            ++it;
            nmed = *(it);
        }
        else {
            --it;
            nmed = *(it);
        }
        if (2 * pos != i + 1) {
            add -= abs(med - nmed);
        }
        med = nmed;
        pos = npos;
        res2[i] = add;
    }
    for (ll i = 1; i <= n; ++i) {
        //cerr << res1[i - 1] << "-" << res2[i - 1] << "-";
        ll pr = res1[i - 1] + res2[i - 1];
        if (i & 1) {
            ll k = i / 2;
            pr -= k * (k + 1);
        }
        else {
            ll k = i / 2;
            pr -= k * k;
        }
        cout << pr << " ";
    }
    cout << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}
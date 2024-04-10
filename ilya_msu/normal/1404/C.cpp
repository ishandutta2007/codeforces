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
#include<unordered_map>
#include<deque>
#include<cmath>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;

class Fenvick {
    vector<int> a;
    ll get(int r) {
        ll res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += a[r];
        return res;
    }
public:
    void build(int n) {
        a.assign(n, 0);
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
    void inc(int pos, int delta) {
        for (; pos < a.size(); pos = pos | (pos + 1)) {
            a[pos] += delta;
        }
    }
};


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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1 - a[i];
        //cout << a[i] << " ";
    }
    //cout << endl;
    vector<pii> ord;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            ord.emplace_back(a[i], -i);
        }
    }
    sort(ord.begin(), ord.end());
    vector<int> dleft(n, -1);
    vector<int> dl2(n, -n - 100);
    vector<int> cleft(n, 0);
    Fenvick ft0, ftr;
    ft0.build(n);
    ftr.build(n);
    SegTree tr;
    tr.build(dl2);
    for (int i = 0; i < ord.size(); ++i) {
        int d = ord[i].first, id = -ord[i].second;
        if (d == 0) {
            cleft[id] += 1;
            dleft[id] = id;
            tr.update(id, -dleft[id]);
            ft0.inc(id, 1);
            ftr.inc(id, 1);
            continue;
        }
        d += ftr.get(id, n - 1) - ft0.get(id, n - 1);

        if (ft0.get(0, id) < d) {
            continue;
        }
        int low = 0, up = id;
        while (up - low > 1) {
            int mid = (up + low) / 2;
            int v = ft0.get(mid, id);
            if (v >= d) 
                low = mid;
            else 
                up = mid;
        }
        //dleft[id] = -tr.getMax(low, id);
        //dleft[id] = max(dleft[id], -1);
        //tr.update(id, -dleft[id]);
        dleft[id] = low;
        //cout << id << " " << low << " " << dleft[id] << endl;
        ft0.inc(dleft[id], 1);
        ftr.inc(id, 1);
        /*


        int l = id;
        for (int j = id - 1; j >= 0; --j) {
            if ((a[j] >= 0) && (a[j] < a[id])) {
                --d;
                l = min(l, dleft[j]);
            }
            if (d == 0) {
                dleft[id] = l;
                if (l >= 0)
                    cleft[l]++;
            }
        }*/
    }
    /*for (int i = 0; i < n; ++i) {
        cout << dleft[i] << " ";
    }
    cout << endl;*/
    vector<pair<pii, int> > qs;
    for (int qq = 0; qq < q; ++qq) {
        int x, y;
        cin >> x >> y;
        qs.emplace_back(pii(x, y), qq);
    }
    sort(qs.rbegin(), qs.rend());
    vector<pii> val(n);
    for (int i = 0; i < n; ++i) {
        val[i] = pii(dleft[i], i);
    }
    sort(val.rbegin(), val.rend());
    Fenvick ft;
    ft.build(n);
    int vid = 0;
    vector<int> res(q);
    for (int i = 0; i < q; ++i) {
        int xx = qs[i].first.first;
        while ((vid < n) && (val[vid].first >= xx)) {
            ft.inc(val[vid].second, 1);
            ++vid;
        }
        int yy = qs[i].first.second;
        res[qs[i].second] = ft.get(xx, n - yy - 1);

    }
    for (int i = 0; i < q; ++i) {
        cout << res[i] << "\n";
    }

    /*    int res = 0;
        for (int i = x; i < n - y; ++i) {
            if (dleft[i] >= x)
                ++res;
        }
        cout << res << endl;
    }*/



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
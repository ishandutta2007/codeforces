#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define setpre(n)           fixed << setprecision(n)
#define Ptest(x)            return cout << x << endl, (void) 0;

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

const int MAXN = 1e5 + 5;

int n, a[MAXN], q;

struct fenwick_tree {
    long long bit[MAXN];
    void upd(int x, int v){
        for (; x <= n; x += x & (-x))
            bit[x] += v;
    }
    long long query(int x){
        long long r = 0;
        for (; x; x -= x & (-x))
            r += bit[x];
        return r;
    }
    long long query(int l, int r){
        return query(r) - query(l - 1);
    }
} bit;

struct node {
    int p, v;
    node ()
        : p(-1), v(-1) {}
    node (int _p, int _v)
        : p(_p), v(_v) {}
    void upd(int _p, int _v) {
        p = _p, v = _v;
    }
    friend node operator + (node l, node r){
        return r.v < l.v ? l : r;
    }
};

struct segtree_min_pos {
    node st[MAXN << 2];
    #define left id << 1, tl, tm
    #define right id << 1 | 1, tm + 1, tr
    void upd(int p, int v, int id = 1, int tl = 1, int tr = n){
        if (p > tr || tl > p) return ;
        if (tl == tr) return st[id].upd(p, v);
        int tm = tl + tr >> 1;
        upd(p, v, left), upd(p, v, right);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    node query(int l, int r, int id = 1, int tl = 1, int tr = n){
        if (l > r || l > tr || tl > r) return node();
        if (l <= tl && tr <= r) return st[id];
        int tm = tl + tr >> 1;
        return query(l, r, left) + query(l, r, right);
    }
} st;

void upd_single(int p, int x){
    bit.upd(p, x - a[p]);
    a[p] = x;
    st.upd(p, a[p]);
}

void Hollwo_Pelw() {
    cin >> n >> q;
    for (int i = 1, x; i <= n; i++){
        cin >> x, upd_single(i, x);
    }
    while (q --) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << bit.query(l, r) << "\n";
        }else if (t == 3){
            int p, x;
            cin >> p >> x;
            upd_single(p, x);
        }else{
            int l, r, x;
            cin >> l >> r >> x;
            while (t) {
                node tmp = st.query(l, r);
                int p = tmp.p, v = tmp.v;
                if (v < x) break;
                upd_single(p, v % x);
            }
        }
    }
}
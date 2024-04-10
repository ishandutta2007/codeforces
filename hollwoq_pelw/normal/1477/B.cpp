/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
    #endif
    int testcases = 1;
    cin >> testcases;
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

const int N = 2e5 + 5;

int n, q, ql[N], qr[N];
string s, f;

struct segment_tree {
    #define tm (tl + tr >> 1)
    #define node id, tl, tr
    #define left id << 1, tl, tm
    #define right id << 1 | 1, tm + 1, tr

    int st[N << 2], lz[N << 2];

    void build(int id = 1, int tl = 1, int tr = n){
        lz[id] = -1;
        if (tl == tr) {
            st[id] = f[tl] - '0';
        } else {
            build(left), build(right);
            st[id] = st[id << 1] + st[id << 1 | 1];
        }
    } 

    void apply(int id, int tl, int tr, int v) {
        st[id] = (tr - tl + 1) * v, lz[id] = v;
    }

    void push(int id, int tl, int tr) {
        if (lz[id] == -1) return ;
        apply(left, lz[id]), apply(right, lz[id]), lz[id] = -1;
    }

    void upd(int l, int r, int v, int id = 1, int tl = 1, int tr = n){
        if (l > r || tl > r || l > tr) return ;
        if (l <= tl && tr <= r) return apply(node, v);
        push(node), upd(l, r, v, left), upd(l, r, v, right);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    int query(int l, int r, int id = 1, int tl = 1, int tr = n){
        if (l > r || tl > r || l > tr) return 0;
        if (l <= tl && tr <= r) return st[id]; push(node);
        return query(l, r, left) + query(l, r, right);
    }

    #undef tm
    #undef node
    #undef left
    #undef right
} st;

void Hollwo_Pelw() {
    cin >> n >> q >> s >> f;
    s = ' ' + s, f = ' ' + f;
    for (int i = 1; i <= q; i++)
        cin >> ql[i] >> qr[i];

    st.build();
    for (int i = q; i >= 1; i--){
        int tot = st.query(ql[i], qr[i]);
        if (tot * 2 == qr[i] - ql[i] + 1)
            return cout << "NO\n", (void) 0;
        st.upd(ql[i], qr[i], (tot * 2 > qr[i] - ql[i] + 1));
    }
    for (int i = 1; i <= n; i++)
        if (st.query(i, i) != s[i] - '0')
            return cout << "NO\n", (void) 0;
    cout << "YES\n";
}
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

const int S = 450, N = 2e5 + 5, M = 1e6 + 6, mod = 1e9 + 7;

inline int add(int a, int b){
    return a + b >= mod ? a + b - mod : a + b;
}

inline int sub(int a, int b){
    return a - b < 0 ? a - b + mod : a - b;
}

inline int mul(int a, int b){
    return 1ll * a * b % mod;
}

int n, qr, a[N], res[N];
vector<pair<int, int>> pr[N];

int p[M], inv[M], vp[M], pv[M];

struct __initial__ {
    __initial__ () {
        for (int i = 1; i < M; i++) p[i] = i, inv[i] = 1;
        for (int i = 2; i < M; i++){
            if (p[i] == i){
                for (int j = 2 * i; j < M; j += i)
                    p[j] = i;
            }
            inv[i] = sub(0, mul(mod / i, inv[mod % i]));
        }
        for (int i = 2; i < M; i++)
            vp[i] = mul(i - 1, inv[i]), pv[i] = mul(i, inv[i - 1]);
    }
} __init__;

struct query {
    int l, r, id;
    query () {}
    query (int _l, int _r, int _id) 
        : l(_l), r(_r), id(_id) {}

    bool operator < (const query &oth) const {
        if (l / S == oth.l / S){
            return (l / S) & 1 ? r > oth.r : r < oth.r;
        }
        return l / S < oth.l / S;
    }

} q[N];

int l = 1, r = 0, ans = 1, cnt[M];

inline void inc(int id) {
    ans = mul(ans, a[id]);
    for (auto x : pr[id]) {
        if (!cnt[x.first])
            ans = mul(ans, vp[x.first]);
        cnt[x.first] += x.second;
    }
}

inline void dec(int id) {
    ans = mul(ans, inv[a[id]]);
    for (auto x : pr[id]) {
        cnt[x.first] -= x.second;
        if (!cnt[x.first])
            ans = mul(ans, pv[x.first]);
    }
}

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1, b; i <= n; i++) {
        cin >> a[i], b = a[i];
        while (b > 1) {
            int v = p[b], c = 0;
            while (b % v == 0)
                b /= v, c ++;
            pr[i].emplace_back(v, c);
        }
    }
    cin >> qr;
    for (int i = 1; i <= qr; i++)
        cin >> q[i].l >> q[i].r, q[i].id = i;
    sort(q + 1, q + qr + 1);

    for (int _ = 1; _ <= qr; _++){
        int nl = q[_].l, nr = q[_].r, id = q[_].id;
        while (r < nr) inc(++ r);
        while (l > nl) inc(-- l);
        while (r > nr) dec(r --);
        while (l < nl) dec(l ++);
        res[id] = ans;
    }

    for (int i = 1; i <= qr; i++)
        cout << res[i] << "\n";
}
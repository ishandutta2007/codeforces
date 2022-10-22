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

#define int long long
const int N = 2e5 + 6, mod = 1e9 + 7;

int fac[N], inv[N];

inline int mul(int a, int b){
    return 1ll * a * b % mod;
}

inline int add(int a, int b){
    return a + b >= mod ? a + b - mod : a + b;
}

inline int sub(int a, int b){
    return a - b < 0 ? a - b + mod : a - b;
}

int binpow(int a, int b) {
    int r = 1;
    while (b){
        if (b&1) r = mul(r, a);
        b >>= 1; a = mul(a, a);
    }
    return r;
}

inline int invr(int a){
    return binpow(a, mod - 2);
}

struct __initial__ {
    __initial__ () {
        fac[0] = fac[1] = inv[0] = inv[1] = 1;
        for (int i = 2; i < N; i++)
            inv[i] = mod - mul(mod / i, inv[mod % i]);
        for (int i = 2; i < N; i++)
            fac[i] = mul(fac[i - 1], i), inv[i] = mul(inv[i - 1], inv[i]);
    }
} __init__;

int C(int k, int n){
    if (k < 0 || k > n) return 0;
    return mul(fac[n], mul(inv[n - k], inv[k]));
}

int solve(int k, int n){
    if (n == 0) return k == 0;
    if (k == 0) return n == 0;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = add(ans, mul(i & 1 ? mod - 1 : 1, 
                mul(C(i, k), binpow(k - i, n))));
    }
    return mul(ans, inv[k]);
}

void Hollwo_Pelw() {
    int n, k, tot = 0; cin >> n >> k;
    for (int i = 1, w; i <= n; i++)
        cin >> w, tot = add(w, tot);
    cout << mul(tot, add(solve(k, n), mul(n - 1, solve(k, n - 1))));
}
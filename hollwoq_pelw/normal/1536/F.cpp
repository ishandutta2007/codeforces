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

const int N = 1e6 + 6, mod = 1e9 + 7;

int fac[N], inv[N];

inline int mul(int a, int b){
    return 1ll * a * b % mod;
}

inline int add(int a, int b){
    return a + b >= mod ? a + b - mod : a + b;
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

int way(int k, int n){
    return C(k, n - 1);
}

void Hollwo_Pelw() {
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        ans = add(ans, mul(add(way(n - i, i), mul(way(n - i - 1, i), 2)), fac[i]));
    }
    cout << mul(ans, 2);
}
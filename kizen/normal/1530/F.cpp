#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

const int mod = 31607;
int inv[31607];

int pw(int x, int y, int mod){
    if(!y) return 1;
    if(y % 2) return pw(x, y - 1, mod) * x % mod;
    int val = pw(x, y / 2, mod);
    return val * val % mod;
}

int one[21][1 << 21];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i < mod; ++i){
        inv[i] = pw(i, mod - 2, mod);
    }
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            a[i][j] = (a[i][j] * inv[10000]) % mod;
        }
    }
    int ans = 1;
    for(int i = 0; i < n; ++i){
        vector<int> gop(1 << n, 1);
        int ag = 1;
        for(int j = 0; j < n; ++j){
            ag = (ag * a[i][j]) % mod;
        }
        for(int j = 0; j < (1 << n); ++j){
            if(j){
                int last = __builtin_ctz(j & -j);
                gop[j] = gop[j ^ (1 << last)] * a[i][last] % mod;
            }
            int now = (ag * inv[gop[j]]) % mod;
            one[i][j] = (gop[j] * (1 - now + mod)) % mod;
        }
        ans = (ans * one[i][0]) % mod;
    }
    for(int j = 1; j < (1 << (n + 2)); ++j){
        int val = (j & ((1 << n) - 1));
        int ocnt = __builtin_popcount(j);
        int prob = 1;
        for(int i = 0; i < n; ++i){
            int now = val;
            if(j & (1 << n)) now |= (1 << i);
            if(j & (1 << (n + 1))) now |= (1 << (n - i - 1));
            prob = (prob * one[i][now]) % mod;
        }
        if(ocnt % 2 == 0) ans = (ans + prob) % mod;
        else ans = (ans - prob + mod) % mod;
    }
    cout << (1 - ans + mod) % mod;
    return 0;
}
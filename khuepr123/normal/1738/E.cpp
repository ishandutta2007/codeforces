/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int fac[maxN];
int inv[maxN];
int ans;

int pw(int num, int coef){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        coef >>= 1;
    }
    return res;
}

void mul(int &v1, int v2){
    v1 %= mod;
    v2 %= mod;
    v1 = (v1 * v2) % mod;
}

int C(int n, int k){
    int ans = fac[n] * inv[k] % mod;
    return ans * inv[n - k] % mod;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    fac[0] = 1;
    inv[0] = 1;
    for1(i, 1, maxN - 1){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = pw(fac[i], mod - 2);
    }
    while(o--){
        cin >> n;
        for1(i, 1, n){
            cin >> a[i];
        }
        if(a[1] == 0 && a[n] == 0){
            a[1] = 1;
            a[n] = 1;
        }
        if(a[1] == 0) reverse(a + 1, a + n + 1);
        int l = 1, r = n;
        ans = 1;
        while(l <= r){
            int s1 = a[l], s2 = 0;
            ++l;
            while(l <= r && s1 != s2){
                if(s1 > s2){
                    s2 += a[r]; --r;
                }
                else{
                    s1 += a[l]; ++l;
                }
            }
            if(s1 != s2) break;
            s1 = 0, s2 = 0;
            while(l <= r && a[l] == 0){
                ++l; ++s1;
            }
            while(l <= r && a[r] == 0){
                --r; ++s2;
            }
            if(l > r){
                mul(ans, pw(2, s1 + 1));
            }
            else{
                // cout << s1 << " " << s2 << endl;
                if(s1 > s2) swap(s1, s2);
                ++s1; ++s2; // number of slot to choose from
                int res = 0;
                for1(i, 0, s1){
                    res += C(s1, i) * C(s2, i) % mod;
                    // cout << i << " " << C(s1, i) * C(s2, i) % mod << endl;
                }
                // cout << res << endl;
                mul(ans, res);
            }
        }
        // mul(ans, pw(2, mod - 2));
        cout << (ans % mod + mod) % mod << endl;
    }
}
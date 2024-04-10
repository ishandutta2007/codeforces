/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
// only when really needed
 
/* GNU G++17 7.3.0: No long long for faster code
   GNU G++17 9.2.0 (64 bit, msys 2): Long long only for faster code */
 
#include <bits/stdc++.h>
  
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long
 
#define sz(a) (int)a.size()
#define pii pair<int,int>
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD2 1000000009
#define EPS 1e-6
 
using namespace std;
 
int power(int x, int n) {
    
    int res = 1;
    
    while (n > 0) {
        
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
        
    }
    
    return res;
}
 
 
int inverse(int x) {
    
    return power(x, MOD - 2);
    
}
 
const int bl = 450;
struct query{
    
    int l, r, id;
    bool operator< (const query& other) {
        if (l / bl != other.l / bl) return l > other.l;
        if ((l / bl) & 1) return r > other.r;
        return r < other.r;
    }
    
};
 
int divisor[1000005], cnt[1000005], a[200005], br[200005], inv[200005], n, q;
int p[1000005], vp[1000005];
vector<query> v;
vector<pii> mp[200005];
 
signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for1(i,2,1000000) if (!divisor[i]) {
        p[i] = (i - 1) * inverse(i) % MOD;
        vp[i] = inverse(p[i]);
        for1(j,1,1000000/i) divisor[i*j] = i;
    }
    
    cin >> n;
    for1(i,1,n) {
        cin >> a[i];
        int b = a[i];
        while (b > 1) {
            
            int r = divisor[b], p = 0;
            while (b % r == 0) {
                b /= r;
                p++;
            }
            mp[i].push_back({r, p});
        
        }
        inv[i] = inverse(a[i]);
    }
    
    cin >> q;
    for1(i,1,q) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r, i});
    }
    
    sort(v.begin(), v.end());
    
    int l = 1, r = 0;
    int ans = 1;
    for (auto q : v) {
        
        while (l > q.l) {
            l--;
            ans = ans * a[l] % MOD;
            
            for (auto i : mp[l]) {
                if (!cnt[i.first]) ans = ans * p[i.first] % MOD;
                cnt[i.first] += i.second;
            }
            
        }
        
        while (r < q.r) {
            r++;
            ans = ans * a[r] % MOD;
            
            for (auto i : mp[r]) {
                if (!cnt[i.first]) ans = ans * p[i.first] % MOD;
                cnt[i.first] += i.second;
            }
        }
        
        while (l < q.l) {
            for (auto i : mp[l]) {
                cnt[i.first] -= i.second;
                if (!cnt[i.first]) ans = ans * vp[i.first] % MOD;
            }
            
            ans = ans * inv[l] % MOD;
            l++;
        }
        
        while (r > q.r) {
            for (auto i : mp[r]) {
                cnt[i.first] -= i.second;
                if (!cnt[i.first]) ans = ans * vp[i.first] % MOD;
            }
            
            ans = ans * inv[r] % MOD;
            r--;
        }
        
        br[q.id] = ans;
        
    }
    
    for1(i,1,q) cout << br[i] << "\n";
    
}
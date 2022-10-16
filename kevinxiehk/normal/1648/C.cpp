#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
const int mod = 998244353;
int fen[200005];
int n, m;
void add(int x, int id) {
    while(id <= 200000) {
        fen[id] += x;
        id += (id & (-id));
    };
}
int query(int id) {
    int ans = 0;
    while(id > 0) {
        ans += fen[id];
        id -= (id & (-id));
    };
    return ans;
}
unordered_map<int, int> cnt;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
void solve(int TC) {
    int fac[200005];
    fac[0] = 1;
    for(int i = 1; i <= 200000; i++) fac[i] = fac[i - 1] * i % mod;
    int invfac[200005];
    int invv[200005];
    for(int i = 0; i <= 200000; i++) invfac[i] = inv(fac[i], mod);
    for(int i = 0; i <= 200000; i++) invv[i] = inv(i, mod);
    int n, m;
    cin >> n >> m;
    int t, arr[m + 5];
    for(int i = 0; i < n; i++) {
        cin >> t;
        cnt[t]++;
        add(1, t);
    }
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    int all = fac[n];
    int lef = n;
    for(auto x: cnt) all = all * invfac[x.se] % mod;
    int ans = 0;
    // cout << all << '\n';
    for(int i = 0; i <= min(n, m); i++) {
        if(i == m) {
            break;
        }
        if(i == n) {
            ans++;
            break;
        }
        int t = query(arr[i] - 1);
        ans += all * t % mod * invv[lef] % mod;
        // cerr << ans << '\n';
        if(cnt[arr[i]] == 0) break;

        all = all * fac[cnt[arr[i]]] % mod;
        all = all * invfac[lef] % mod;

        cnt[arr[i]]--;
        lef--;
        add(-1, arr[i]);

        all = all * fac[lef] % mod;
        all = all * invfac[cnt[arr[i]]] % mod;
    }
    cout << ans % mod << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}
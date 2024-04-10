    #include <bits/stdc++.h>
    #define mp make_pair
    #define pb emplace_back
    #define fi first
    #define se second
    #define int long long
    #define ick cout<<"ickbmi32.9\n"
    using namespace std;
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
    int pwr[100005];
    int mod = 998244353;
    int ncr(int n, int r) {
        if(r > n || r < 0) return 0;
        return pwr[n] * inv(pwr[r], mod) % mod * inv(pwr[n - r], mod) % mod;
    }
    void solve(int TC) {
        int n;
        cin >> n;
        int lb = 0, le = 0, rb = 0, re = 0;
        char l, r;
        int xx = 0;
        int ans = 0;
        bool needminus = true;
        for(int i = 0; i < n; i++) {
            cin >> l >> r;
            if(l == '?') le++;
            if(l == 'B') lb++;
            if(r == '?') re++;
            if(r == 'B') rb++;
            if(r == l && r != '?') needminus = false;
            else if(r == l) xx++;
        }
        for(int i = 0; i <= n; i++) {
            // cerr << i << '\n' << ncr(le, i - lb) * ncr(re, n - i - rb) % mod << '\n' << ncr(le, i - lb) << '\n' << ncr(re, n - i - rb) << '\n';;
            ans += ncr(le, i - lb) * ncr(re, n - i - rb) % mod;
            ans %= mod;
        }
        if(needminus) {
            int subs = 0;
            int lw = n - le - lb;
            int rw = n - re - rb;
            subs = bm(2, xx, mod);
            if(lw + rb == 0 || lb + rw == 0) subs--;
            if(xx == n) subs--;
            ans -= subs;
            ans = (ans % mod + mod) % mod;
        }
        cout << ans << '\n';
    }
    signed main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        int t = 1;  
        pwr[0] = 1;
        for(int i = 1; i <= 100000; i++) pwr[i] = pwr[i - 1] * i % mod;
        // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
        //while(t--) solve();
        for(int i = 1; i <= t; i++) solve(i);
        return 0;
    }
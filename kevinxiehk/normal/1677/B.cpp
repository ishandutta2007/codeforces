#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
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
void solve(int TC) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int tot = n * m;
    int ans[tot + 5];
    for(int i = 0; i <= tot; i++) ans[i] = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i; j < tot; j += m) {
            if(s[j] == '1') {
                ans[j]++;
                break;
            }
        }
    }
    for(int i = 1; i <= tot; i++) ans[i] += ans[i - 1];
    int ans2[tot + 5];
    for(int i = 0; i <= tot; i++) ans2[i] = 0;
    int add[m + 5];
    for(int i = 0; i <= m; i++) add[i] = 0;
    int tc = 0;
    for(int i = 0; i < tot; i++) {
        tc += s[i] - '0';
        if(i >= m) tc -= s[i - m] - '0';
        if(tc > 0) ans2[i]++;
        
    }
    // for(int i = 0; i < tot; i++) cout << ans[i] << ' ' << ans2[i] << '\n';
    for(int i = 0; i < tot; i++) {
        cout << ans[i] + ans2[i] + add[i % m] << ' ';
        add[i % m] += ans2[i];
    }
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}
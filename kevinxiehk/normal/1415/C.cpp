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
    // wtf wheres wrong
    // not like he can solve 3 in 8 mins tho

    int n, p, k;
    cin >> n >> p >> k;
    // p--;
    string s;
    cin >> s;
    s = "+" + s;
    int x, y;
    cin >> x >> y;
    int ans[n + 5]; 
    for(int i = 0; i <= n; i++) ans[i] = y * i;
    int aa = inf;
    for(int i = 0; i < k; i++) {
        int xx = 0;
        if(p + i > n) break;
        for(int j = p + i; j <= n; j += k) {
            ans[i] = min(ans[i], y * i + xx * y * k);
            xx++;
            if(s[j] == '0') {
                ans[i] += x;
            }
            
        }
        aa = min(aa, ans[i]);
    }
    cout << aa << '\n';
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
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
    int n;
    cin >> n;
    map<string, int> cnt;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        cnt[s]++;
    }
    int ans = 0;
    for(int i = 0; i < 11 * 11; i++) {
        string ss = "aa";
        ss[0] += i % 11;
        ss[1] += i / 11;
        for(int j = 0; j < 11; j++) {
            string sss = "aa";
            sss[0] += j;
            sss[1] = ss[1];
            if(sss != ss) ans += cnt[ss] * cnt[sss];
        }
        for(int j = 0; j < 11; j++) {
            string sss = "aa";
            sss[1] += j;
            sss[0] = ss[0];
            if(sss != ss) ans += cnt[ss] * cnt[sss];
        }
    }
    cout << ans / 2 << '\n';

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
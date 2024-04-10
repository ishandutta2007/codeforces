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
void solve(int TC) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    int ls = -1;
    for(int i = 0; i < n; i++) {
        if(s1[i] != s2[i]) {
            ans += 2;
            continue;
        }
        if(s1[i] == '0') {
            ans++;
            if(i > 0 && s1[i - 1] == s2[i - 1] && s1[i - 1] == '1' && ls < i - 1) {
                ans++;
                ls = i;
            }
        }
        else {
            if(i > 0 && s1[i - 1] == s2[i - 1] && s1[i - 1] == '0' && ls < i - 1) {
                ans++;
                ls = i;
            }
        }
    }
    cout << ans << '\n';
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
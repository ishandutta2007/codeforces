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
void solve(int TC) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt01 = 0, cnt00 = 0, cnt11 = 0, cnt10 = 0;
    for(int i = 0; i < n; i++) {
        if(s1[i] == '0' && s2[i] == '1') {
            cnt01++;
        }
        if(s1[i] == '0' && s2[i] == '0') {
            cnt00++;
        }
        if(s1[i] == '1' && s2[i] == '1') {
            cnt11++;
        }
        if(s1[i] == '1' && s2[i] == '0') {
            cnt10++;
        }
    }
    int ax = cnt11 + cnt10;
    int bx = cnt11 + cnt01;
    if(bx != ax && bx != n - ax + 1) {
        cout << "-1\n";
        return;
    }
    if(s1 == s2) {
        cout << "0\n";
        return;
    }
    int odd = cnt01 + cnt10;
    int even = cnt00 + cnt11;
    int ans = n + 5;
    if(even % 2 != 0 && cnt11 != 0 && cnt00 == cnt11 - 1) {
        ans = min(ans, even);
    }
    if(odd % 2 != 1 && cnt10 != 0 && cnt01 == cnt10) {
        ans = min(ans, odd);
    }
    if(ans == n + 5) ans = -1;
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
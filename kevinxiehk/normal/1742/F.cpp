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
    int freq[2][30];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 30; j++) freq[i][j] = 0;
    }
    freq[0][0] = freq[1][0] = 1;
    bool ha1 = false;
    bool ha2 = false;
    while(n--) {
        int t, x;
        string s;
        cin >> t >> x >> s;
        if(t == 1) {
            for(auto c: s) {
                if(c != 'a') ha1 = true;
                else freq[0][0] += x;
            }
        }
        else {
            for(auto c: s) {
                if(c != 'a') ha2 = true;
                else freq[1][0] += x;
            }
        }
        if(ha2) cout << "YES\n";
        else if(ha1) cout << "NO\n";
        else if(freq[0][0] < freq[1][0]) cout << "YES\n";
        else cout << "NO\n";
    }
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
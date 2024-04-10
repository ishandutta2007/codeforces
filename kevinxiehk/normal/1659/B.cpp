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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> moves;
    int kk = k;
    for(int i = 0; i < n; i++) {
        if(k % 2 == 1 && s[i] == '0') {
            s[i] = '1';
            moves.pb(0);
        } 
        else if(k % 2 == 0 && s[i] == '1') {
            s[i] = '1';
            moves.pb(0);
        }
        else if(kk > 0) {
            kk--;
            s[i] = '1';
            moves.pb(1);
        }
        else {
            if(k % 2) s[i] ^= 1;
            moves.pb(0);
        }
    }   
    if(kk > 0) {
        if(kk % 2 == 1) {
            s[n - 1] = '0';
        }
        moves[n - 1] += kk;
    }
    cout << s << '\n';
    for(auto x: moves) cout << x << ' ';
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
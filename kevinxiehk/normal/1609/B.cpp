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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < n - 2; i++) {
        if(s.substr(i, 3) == "abc") count++;
    }
    int x;
    char c;
    while(q--) {
        cin >> x >> c;
        x--;
        int tc = 0;
        for(int i = max(0LL, x - 2); i <= x; i++) {
            if(s.substr(i, 3) == "abc") tc++;
        }
        s[x] = c;
        for(int i = max(0LL, x - 2); i <= x; i++) {
            if(s.substr(i, 3) == "abc") tc--;
        }
        count -= tc;
        cout << count << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}
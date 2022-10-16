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
    cin >> n >> m;
    if(m < n) {
        cout << "No\n";
        return;
    }
    if(n & 1) {
        cout << "Yes\n";
        for(int i = 1; i < n; i++) cout << "1 ";
        cout << m - n + 1 << '\n';
    }
    else {
        if(m & 1) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
            for(int i = 1; i < n - 1; i++) cout << "1 ";
            int le = m - n + 2;
            cout << le / 2 << ' ' << le / 2 << '\n';
        }
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
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
int ans[1005];
bool taken[1005];
int arr[1005];
int n;
bool rec(int pos) {
    if(pos == n + 1) return true;
    for(int i = 1; i <= n; i++) {
        if(!taken[i] && i != arr[pos]) {
            taken[i] = true;
            ans[pos] = i;
            if(rec(pos + 1)) return true;
            taken[i] = false;
        }
    }
    return false;
}
void solve(int TC) {
    // int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    if(n == 1) {
        cout << "-1\n";
        return;
    }
    
    for(int i = 0; i <= n; i++) {
        taken[i] = false;
    }
    rec(1);
    for(int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
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
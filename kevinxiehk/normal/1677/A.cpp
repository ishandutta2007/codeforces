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
int fen[5005];
int n;
void add(int id) {
    for(; id <= n; id += id & -id) fen[id]++;
}
int sum(int id) {
    int sm = 0;
    for(; id > 0; id -= id & -id) sm += fen[id];
    return sm;
}
void solve(int TC) {
    // int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 1; i <= n; i++) fen[i] = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int tc = 0;
        for(int j = i + 1; j <= n; j++) {
            if(arr[j] < arr[i]) ans += tc;
            tc += sum(arr[j]);
        }
        add(arr[i]);
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
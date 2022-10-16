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
    int arr[n + 5];
    int t = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        t += arr[i];
    }
    if(!isprime(t)) {
        cout << n << '\n';
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    cout << n - 1 << '\n';
    bool aaa = true;
    for(int i = 1; i <= n; i++) {
        if(!(aaa && (arr[i - 1] % 2 == 1))) cout << i << ' ';
        else aaa = false;
    }
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
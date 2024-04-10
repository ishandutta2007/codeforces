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
    int n, a, b;
    cin >> n >> a >> b;
    if(abs(a - b) > 1 || a + b >= n - 1) {
        cout << "-1\n";
        return;
    } 
    bool flip = false;
    if(a < b) {
        swap(a, b);
        flip = true;
    }
    if(a > b) {
        int arr[n + 5];
        for(int i = 1; i <= n; i++) arr[i] = i + 1;
        arr[1] = 1;
        arr[n] = 2;
        for(int i = 1; i < a; i++) {
            swap(arr[i * 2 + 1], arr[i * 2]);
        }
        if(flip) {
            for(int i = 1; i <= n; i++) arr[i] = n + 1 - arr[i];
        }
        for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    if(a == b) {
        int arr[n + 5];
        for(int i = 1; i <= n; i++) arr[i] = i;
        for(int i = 1; i <= a; i++) {
            swap(arr[i * 2 + 1], arr[i * 2]);
        }
        for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
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
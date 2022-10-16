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
    int arr[3], m;
    cin >> arr[0] >> arr[1] >> arr[2] >> m;
    sort(arr, arr + 3);
    if(m > arr[0] + arr[1] + arr[2] - 3) {
        cout << "NO\n";
        return;
    }
    int t = arr[2] - arr[1];
    arr[2] -= min(t, m);
    m -= min(t, m);
    t = (arr[1] - arr[0]) / 2;
    arr[2] -= min(t, m);
    arr[1] -= min(t, m);
    m -= min(t, m) * 2;
    t = (arr[0] - 1) / 3;
    arr[2] -= min(t, m);
    arr[1] -= min(t, m);
    arr[0] -= min(t, m);
    m -= min(t, m) * 3;
    if(m >= 2) arr[2]--;
    if(m >= 1) arr[1]--;
    if(arr[2] > arr[0] + arr[1] + 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
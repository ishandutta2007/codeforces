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
int getsum(int a, int b) {
    int k, kk;
    cout << "and " << a + 1 << ' ' << b + 1 << endl;
    cin >> k;
    cout << "or " << a + 1 << ' ' << b + 1 << endl;
    cin >> kk;
    return k + kk;
}
void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n + 5];
    for(int i = 1; i < n; i++) {
        arr[i] = getsum(0, i);
    }
    int t = getsum(1, 2);
    arr[0] = (arr[1] + arr[2] - t) / 2;
    for(int i = 1; i < n; i++) arr[i] -= arr[0];
    sort(arr, arr + n);
    cout << "finish " << arr[k - 1] << endl;
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}
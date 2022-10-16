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
void solve() {
    int n;
    cin >> n;
    int arr[n + 5]; int sum = 0;
    vector<int> one;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= 2;
        sum += arr[i];
        if(arr[i]) one.pb(i);
    }
    if(n % 2) {
        if(sum != n / 2 && sum != n / 2 + 1) {
            cout << "-1\n"; return;
        }
        int ans = 0;
        if(sum == n / 2) {
            for(int i = 0; i < n / 2; i++) {
                ans += abs(one[i] - i * 2 - 1);
            }
        }
        else {
            for(int i = 0; i < n / 2 + 1; i++) {
                ans += abs(one[i] - i * 2);
            }
        }
        cout << ans << '\n';
    }
    else {
        if(sum != n / 2) {
            cout << "-1\n"; return;
        }
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n / 2; i++) {
            ans1 += abs(one[i] - i * 2);
        }
        for(int i = 0; i < n / 2; i++) {
            ans2 += abs(one[i] - i * 2 - 1);
        }
        cout << min(ans1, ans2) << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}
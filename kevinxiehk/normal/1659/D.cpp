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
    int n;
    cin >> n;
    int arr[n + 5];
    int ans[n + 5];
    int sum = 0;
    // vector<int> ans;
    for(int i = 1; i <= n; i++) {cin >> arr[i]; sum += arr[i];}
    sum /= n;
    int zerocnt = n - sum;

    int zeropos[n + 5];
    for(int i = 1; i <= zerocnt; i++) zeropos[i] = -1;
    for(int i = zerocnt + 1; i <= n; i++) zeropos[i] = n + 1;
    for(int i = n; i >= 1; i--) {
        if(zeropos[i] == -1) {
            zeropos[i] = i;
            ans[i] = 0;
        }
        else {
            if(arr[i] == zeropos[i] - i && zerocnt > 0) {
                ans[i] = 0;
                zeropos[zerocnt] = i;
                zerocnt--;
            }
            else ans[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
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
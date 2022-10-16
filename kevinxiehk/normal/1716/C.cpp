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

    // dont want to deal with this gay task??

    // this is seriously harder than qE

    int n;
    cin >> n;
    int arr[2][n + 5];
    for(int i = 0; i < 2; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];
    arr[0][0] = -1;
    int aa[2][n + 5]; 
    aa[0][n - 1] = max(arr[0][n - 1] + 1, arr[1][n - 1]) + 1;

    for(int i = n - 2; i >= 0; i--) {
        aa[0][i] = max(max(arr[0][i] + 1 + (n - i) * 2 - 1, aa[0][i + 1] + 1), arr[1][i] + 1);
    }
    
    aa[0][n - 1] = arr[0][n - 1] + 1;
    for(int i = n - 2; i > 0; i--) {
        aa[0][i] = max(max(arr[0][i] + 1 + (n - i - 1) * 2, aa[0][i + 1] + 1), arr[1][i + 1] + 1);
    }

    aa[1][n - 1] = arr[1][n - 1] + 1;
    for(int i = n - 2; i >= 0; i--) {
        aa[1][i] = max(max(arr[1][i] + 1 + (n - i - 1) * 2, aa[1][i + 1] + 1), arr[0][i + 1] + 1);
    }

    // for(int i = 0; i < 2; i++) {
    //     for(int j = 0; j < n; j++) cout << aa[i][j] << ' ';
    //     cout << '\n';
    // }

    int best = aa[0][0];
    int time = -1;
    int y = 0;
    int left = n * 2;

    for(int i = 0; i < n; i++) {
        time = max(time, arr[y][i]) + 1;
        left--;

        y ^= 1;

        time = max(time, arr[y][i]) + 1;
        left--;
        best = min(best, max(time + left, aa[y][i]));
    }
    cout << best << '\n';
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
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
int arr[50005];
int x;
bool check(int xx, int id) {
    int ts = 0, tc = 0;
    while((xx & 1) && id >= 0) {
        ts += arr[id] - x;
        id--;
        tc++;
        xx /= 2;
        if(tc >= 2 && ts < 0) return false; 
        // cout << xx << ' ' << id << ' ' << ts << ' ' << tc << '\n';
    }
    if(tc >= 2 && ts < 0) return false;
    return true;
}
void solve(int TC) {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] += 100005;
    }
    cin >> x;
    x += 100005;

    int dp[n + 5][8];
    for(int i = 0; i < n; i++) for(int j = 0; j < 8; j++) dp[i][j] = 0;
    for(int i = 0; i < 8; i++) dp[0][i] = (i & 1);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < 8; j++) {
            int nx = ((j * 2) % 8);
            dp[i + 1][nx] = max(dp[i + 1][nx], dp[i][j]);
            if(check(nx + 1, i + 1)) dp[i + 1][nx + 1] = max(dp[i + 1][nx + 1], dp[i][j] + 1);
            else dp[i + 1][nx + 1] = -inf;
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }
    int ans = 0;
    for(int i = 0; i < 8; i++) {
        // cout << dp[n - 1][i] << ' ';
        ans = max(ans, dp[n - 1][i]);
    }
    cout << '\n' << ans << '\n';
    
    // cout << max(max(dp[n - 1][0], dp[n - 1][1]), max(dp[n - 1][2], dp[n - 1][3])) << '\n';
    // int ans = 0;
    // for(int i = 0; i < n; i++) {
    //     if(arr[i] >= x) {
    //         arr[i] *= -1;
    //         ans++;
    //     }
    // }
    // int start = 0;
    // bool stcan = true, edcan = false;
    // int st;
    // int ed;
    // while(start < n && arr[start] < 0) {
    //     start++;
    //     stcan = false;
    // }
    // if(start == n) {
    //     cout << n << '\n';
    //     return;
    // }
    // for(int i = start; i < n; i++) {
    //     if(arr[i] < 0) continue;
    //     if(i == 0) {
    //         st = i;
    //         stcan = true;
    //     }
    //     else if(arr[i] > 0 && arr[i - 1] < 0) {
    //         st = i;
    //         stcan = (arr[i] - arr[i - 1]) >= x * 2;
    //     }
    //     if(i == n - 1) {
    //         ed = i;
    //         edcan = true;
    //     }
    //     else if(arr[i] > 0 && arr[i + 1] < 0){
    //         ed = i;
    //         edcan = (arr[i] - arr[i + 1]) >= x * 2;
    //     }   
    //     if(ed == i) {
    //         cout << st << ' ' << ed << ' ' << stcan << ' ' << edcan << '\n';
    //         if(!stcan) st++;
    //         if(!edcan) ed--;
    //         int len = ed - st + 2;
    //         ans += len / 2;
    //     }
    // }
    // cout << ans << '\n';
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
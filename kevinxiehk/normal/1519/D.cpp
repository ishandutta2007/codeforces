#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    int a[n + 5], b[n + 5];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i] * b[i];
    int dx[n + 5][n + 5];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            dx[i][j] = a[i] * b[j] + b[i] * a[j] - a[i] * b[i] - a[j] * b[j];
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int l = 1;
        int curr = 0;
        while(i - l >= 0 && i + l < n) {
            curr += dx[i - l][i + l];
            l++;
            mx = max(curr, mx);
        }
        l = 0;
        curr = 0;
        while(i - l - 1>= 0 && i + l < n) {
            curr += dx[i - l - 1][i + l];
            l++;
            mx = max(curr, mx);
        }
    }
    cout << sum + mx << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    //cin >> t;
    
    while(t--) solve();
    return 0;
}
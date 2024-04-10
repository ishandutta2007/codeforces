#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n;cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int pt1 = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[pt1]) {
            cnt++; pt1++;
        }
    }
    cout << cnt << '\n';
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
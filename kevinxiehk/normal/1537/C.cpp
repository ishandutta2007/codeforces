#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int mi = arr[n - 1] - arr[0] + 999, mii = -1;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i + 1] - arr[i] < mi) {
            mi = arr[i + 1] - arr[i];
            mii = i;
        }
    }
    cout << arr[mii] << ' ';
    for(int i = mii; i < n; i++) {
        if(i != mii && i != mii + 1) cout << arr[i] << ' ';
    }
    for(int i = 0; i < mii; i++) {
        if(i != mii && i != mii + 1) cout << arr[i] << ' ';
    }
    cout << arr[mii + 1] << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();
    
    return 0;
}
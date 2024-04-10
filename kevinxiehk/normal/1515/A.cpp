#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, x;
    cin >> n >> x;
    int arr[n + 5];
    int sum = 0;
    for(int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
    if(sum == x) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    sort(arr, arr + n);
    int t = 0;
    for(int i = 0; i < n; i++) {
        if(t + arr[i] == x) {
            cout << arr[i + 1] << ' ' << arr[i] << ' ';
            t += arr[i] + arr[i + 1];
            i++;
        }
        else{
            t += arr[i];
            cout << arr[i] << ' ';
        }
    }
    cout << '\n';
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
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    long a[n];
    long max=-1,min=-1;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        if (a[i] >= 0 && ((i>0 && a[i-1]==-1) || (i<n-1 && a[i+1]==-1))){
            if (max == -1 || a[i] > max) max = a[i];
            if (min == -1 || a[i] < min) min = a[i];
        }
    }
    //cout << max << ' ' << min << ' ';
    long k = (max+min)/2;
    if (k == -1){
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    long res = -1;
    for (int i = 0; i < n; i++){
        if (a[i] == -1){
            a[i] = k;
        }
        if (i > 0){
            if (res == -1 || res < abs(a[i]-a[i-1])) res = abs(a[i]-a[i-1]);
        }
    }
    cout << res << ' ' << k << endl;
    
}
int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
}
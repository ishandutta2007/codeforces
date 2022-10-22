#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, n, a[(int) 1e5 + 5];

signed main(){
    cin >> t; while(t--){
        cin >> n;
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i]; sum += a[i];
            ans = min(ans, sum);
        }
        cout << -ans << endl;
    }
}
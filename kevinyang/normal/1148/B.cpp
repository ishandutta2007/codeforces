#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,ta,tb,k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int>a(n+1);
    vector<int>b(m+1);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for(int i = 1; i<=m; i++){
        cin >> b[i];
    }
    if(m<=k||n<=k){
        cout << "-1\n";
        return 0;
    }
    int mx = 0;
    int ans = b[1]+tb;
    for(int i = 1; i<=n; i++){
        int idx = lower_bound(b.begin(),b.end(),a[i]+ta)-b.begin();
        int rem = i-1+m-(idx-1);
        mx = max(mx,rem);
        if(rem<=k){
            cout << "-1\n";
            return 0;
        }
        int remain = rem-k;
        int ind = m-remain+1;
        if(ind>=idx){
            ans = max(ans,b[ind]+tb);
        }
    }
    
    cout << ans << "\n";
    return 0;
}
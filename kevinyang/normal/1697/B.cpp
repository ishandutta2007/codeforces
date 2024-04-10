#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int>psa(n+1);
    for(int i = 1; i<=n; i++){
        psa[i] = psa[i-1]+arr[i];
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << psa[n-x+y]-psa[n-x] << "\n";
    }
    return 0;
}
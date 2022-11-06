#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int>psa(n+1);
    vector<int>psa2(n+1);
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i = 2; i<=n; i++){
        if(arr[i]-arr[i-1]>=0){
            psa[i]+=arr[i]-arr[i-1];
        }
        else{
            psa2[i]+=abs(arr[i]-arr[i-1]);
        }
        psa[i]+=psa[i-1];
        psa2[i]+=psa2[i-1];
    }
    while(m--){
        int x,y;
        cin >> x >> y;
        if(x<y){
            cout << psa2[y]-psa2[x] << "\n";
        }
        else{
            cout << psa[x]-psa[y] << "\n";
        }
    }
    return 0;
}
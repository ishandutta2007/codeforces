#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,pair<int,int>>>arr(m);
        for(int i = 0; i<m; i++){
            int x,y;
            cin >> x >> y;
            arr[i] = {y,{x,i+1}};
        }
        sort(arr.begin(),arr.end());
        vector<pair<int,int>>a;
        int sum = 0;
        for(int i = 0; i<2*n; i++){
            sum+=arr[i].first;
            a.push_back(arr[i].second);
        }
        sort(a.begin(),a.end());
        cout << sum << "\n";
        for(int i = 0; i<n; i++){
            cout << a[i].second << " " << a[2*n-i-1].second << "\n";
        }
    }
    return 0;
}
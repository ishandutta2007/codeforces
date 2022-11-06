#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin >>t;
    while(t--){
        int n,m; cin >>n >> m;
        vector<vector<int>>arr(n+1,vector<int>(m+1));
        for(int i =1; i<=n; i++){
            for(int j=1;j<=m; j++){
                cin >> arr[i][j];
            }
        }
        int low = 0; int high = (int)2e9;
        int mid = (low+high)/2;
        while(low+1< high){
            bool f = true;
            for(int j=1; j<=m; j++){
                int cnt = 0;
                for(int i = 1; i<=n; i++){
                    if(arr[i][j]>=mid)cnt++;
                }
                if(cnt==0)f = false;
            }
            bool f2 = false;
            for(int i = 1;i<=n; i++){
                int cnt = 0;
                for(int j= 1; j<=m; j++){
                    if(arr[i][j]>=mid){
                        cnt++;
                    }
                }
                if(cnt>=2)f2 = true;
            }
            if(f&&f2){
                low = mid;
            }
            else{
                high = mid;
            }
            mid = (low+ high)/2;
        }
        cout << low << "\n";
    }
    return 0;
}
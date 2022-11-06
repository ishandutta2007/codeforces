#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        int low = 0; int high = (int)2e9; int mid = (low+high)/2;
        while(low+1<high){
            vector<int>a(n+1);
            for(int i = 1; i<=n; i++){
                a[i] = arr[i];
            }
            vector<int>mx(n+1);
            for(int i = 1; i<=n; i++){
                mx[i] = a[i]/3;
            }
            bool f = true;
            for(int i = n; i>=3; i--){
                if(a[i]<mid)f = false;
                int v = min((a[i]-mid)/3,mx[i]);
                v = max(v,0LL);
                a[i]-=3*v;
                a[i-1]+=v;
                a[i-2]+=2*v;
            }
            for(int i = 1; i<=n; i++){
                if(a[i]<mid)f = false;
            }
            if(f){
                low = mid;
            }
            else{
                high = mid;
            }
            mid = (low+high)/2;
        }
        cout << low << "\n";
    }
    return 0;
}
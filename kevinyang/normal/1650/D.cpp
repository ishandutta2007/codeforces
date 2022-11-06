#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>a, vector<int>b, int n){
    bool f = true;
    for(int i = 0; i<n; i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(2*n);
        vector<int>a(n);
        for(int i = 0; i<n; i++){
            a[i] = i+1;
        }
        vector<int>idx(n+1);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            idx[arr[i]] = i;
        }
        for(int i = 0; i<n; i++){
            arr[i+n] = arr[i];
        }
        vector<int>ans(n+1);
        for(int i = 2; i<=n; i++){
            int num = 0;
            for(int j = idx[i]; j<2*n; j++){
                if(arr[j]<i){
                    num = arr[j];
                    break;
                }
            }
            int ind = 0;
            for(int j = 0; j<n; j++){
                if(a[j]==num){
                    ind = j;
                    break;
                }
            }
            ans[i-1] = (i-1-ind)%(i-1);
            vector<int>b(n);
            for(int j = 0; j<n; j++){
                if(j<i-1){
                    int ni = j-ind+(i-1);
                    ni%=(i-1);
                    b[ni] = a[j];
                }
                else{
                    b[j] = a[j];
                }
            }
            for(int j = 0; j<n; j++){
                a[j] = b[j];
            }
        }
        while(!check(arr,a,n)){
            ans[n]++;
            int temp = a[n-1];
            for(int i = n-1; i>0; i--){
                a[i] = a[i-1];
            }
            a[0] = temp;
        }
        for(int i = 1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
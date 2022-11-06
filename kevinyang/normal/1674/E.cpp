#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Sparse{
    vector<int>logs;
    vector<vector<int>>dp;
    int ln;
    int size;
    void init(int n, vector<int>arr){
        size = n;
        logs.resize(n+1);
        dp.resize(n+1);
        ln = 0;
        for(int i = 1; i<=n; i*=2){
            logs[i] = ln; ln++;
        }
        for(int i = 1; i<=n; i++){
            dp[i].resize(ln+1);
            logs[i] = max(logs[i],logs[i-1]);
            dp[i][0] = arr[i];
        }
        for(int i = 1; i<=ln; i++){
            for(int j = 1; j+(1<<i)-1<=n; j++){
                dp[j][i] = min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
            }
        }
    }
    int query(int l, int r){
        int lg = logs[r-l+1];
        return min(dp[l][lg],dp[r-(1<<lg)+1][lg]);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    Sparse sparse;
    sparse.init(n,arr);
    int ans = (int)1e18;
    for(int i = 2; i<=n; i++){
        int x = arr[i-1]; int y = arr[i];
        if(x>y)swap(x,y);
        int v = 0;
        if(y>2*x){
            v = (y+1)/2;
        }
        else{
            v = (x+y+2)/3;
        }
        ans = min(ans,v);
    }
    for(int i = 3; i<=n; i++){
        int x = arr[i-2]; int y = arr[i];
        if(x>y)swap(x,y);
        int v = min(x,y)+(max(x,y)-min(x,y)+1)/2;
        ans = min(ans,v);
    }
    for(int i = 4; i<=n; i++){
        int v = sparse.query(1,i-3);
        int val = (v+1)/2 + (arr[i]+1)/2;
        ans = min(ans,val);
    }
    cout << ans << "\n";
    return 0;
}
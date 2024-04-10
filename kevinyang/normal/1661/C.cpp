#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int n, int m, vector<int>a){
    int ans = 0;
    int x = 0; int y = 0;
    for(int i = 1; i<=n; i++){
        int v = (m-a[i]);
        if(v%2==1)x++;
        y+=v/2;
    }
    int v = min(x,y);
    ans+=2*v;
    x-=v; y-=v;
    if(x>0){
        ans+=2*x-1;
    }
    else{
        ans+=4*(y/3);
        y%=3;
        if(y==1)ans+=2;
        if(y==2)ans+=3;
    }
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        int mx = 0;
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            mx = max(mx,arr[i]);
        }
        cout << min(solve(n,mx,arr),solve(n,mx+1,arr)) << "\n";
    }
    return 0;
}
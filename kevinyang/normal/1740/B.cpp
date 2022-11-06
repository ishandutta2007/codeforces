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
        vector<pair<int,int>>arr(n);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int x,y;
            cin >> x >> y;
            if(x<y){
                swap(x,y);
            }
            arr[i] = {x,y};
            ans+=x*2+y*2;
        }
        sort(arr.begin(),arr.end());
        for(int i = 1; i<n; i++){
            ans-=2*arr[i-1].first;
        }
        cout << ans << '\n';
    }
    return 0;
}
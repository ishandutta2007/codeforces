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
        int ans = -1;
        map<int,int>hm;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            hm[x]++;
            if(hm[x]>=3){
                ans = x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
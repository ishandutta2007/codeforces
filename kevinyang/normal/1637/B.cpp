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
        int cnt = 0;
        int ans = 0;
        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            if(x==0){
                ans+=i*(n-i+1);
            }
        }
        
        for(int i = 1; i<=n; i++){
            ans+=i*(n-i+1);
        }
        cout << ans << "\n";
    }
    return 0;
}
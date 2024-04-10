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
        vector<int>psa(n+1);
        for(int i = 1; i<=n; i++){
            psa[i] = psa[i-1]+arr[i];
        }
        int x;
        cin >> x;
        int ans = 0;
        int cur = 0;
        for(int i = 1; i<=n; i++){
            if(cur==0){
                ans++;
                cur++;
                continue;
            }
            else if(cur==1){
                if(psa[i]-psa[i-2]>=2*x){
                    ans++;
                    cur++;
                }
                else{
                    cur = 0;
                }
            }
            else{
                if(psa[i]-psa[i-2]>=2*x&&psa[i]-psa[i-3]>=3*x){
                    ans++;
                    cur++;
                }
                else{
                    cur = 0;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
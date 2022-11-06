#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        int n = r-l+1;
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        if(n%2==0){
            int ans = 0;
            for(int i = 0; i<20; i++){
                int c = 0; int c2 = 0;
                for(int j = 0; j<n; j++){
                    if(j&(1<<i))c++;
                    if(arr[j]&(1<<i))c2++;
                }
                if(c==c2)continue;
                assert(c+c2==n);
                ans+=(1<<i);
            }
            cout << ans << "\n";
        }
        else{
            int sum = 0;
            for(int i = 0; i<n; i++){
                sum^=i;
                sum^=arr[i];
            }
            cout << sum << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>freq(31);
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            for(int j = 0; j<31; j++){
                if(x&(1<<j)){
                    freq[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 30; i>=0; i--){
            if(k>=(n-freq[i])){
                k-=(n-freq[i]);
                ans+=(1<<i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
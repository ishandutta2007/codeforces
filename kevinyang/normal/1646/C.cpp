#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int>fact(17);
    fact[0] = 1;
    for(int i = 1; i<=16; i++){
        fact[i] = fact[i-1]*i;
    }
    while(t--){
        int n;
        cin >> n;
        int ans = (int)1e9;
        for(int i = 0; i<(1<<17); i++){
            int sum = 0;
            for(int j = 0; j<17; j++){
                if(i&(1<<j)){
                    sum+=fact[j];
                }
            }
            if(sum<=n){
                ans = min(ans,(int)__builtin_popcountll(i)+(int)__builtin_popcountll(n-sum));
                if((int)__builtin_popcountll(i)+(int)__builtin_popcountll(n-sum)==0){
                    //cout << i << "\n";
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int ans = b-a;
        for(int i = b; i<=3*b; i++){
            int val = 0;
            int mx = 0;
            bool bad = false;
            for(int j = 25; j>=0; j--){
                if(i&(1<<j)){
                    if(a&(1<<j)){

                    }
                    else{
                        mx = j;
                    }
                }
                else{
                    if(a&(1<<j)){
                        bad = true;
                        break;
                    }
                }
            }
            if(!bad)mx = 0;
            for(int j = 25; j>=mx; j--){
                if(i&(1<<j)){
                    if(a&(1<<j)){
                        val+=(1<<j);
                    }
                }
            }
            if(bad){
                val = (val|(1<<mx));
            }
            ans = min(ans,i-b+val-a+1);
        }
        cout << ans << "\n";
    }
    return 0;
}
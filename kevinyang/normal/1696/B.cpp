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
        bool f = false;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            if(x==0){
                if(f){
                    f = false;
                    cnt++;
                }
            }
            else{
                f = true;
            }
        }
        if(f)cnt++;
        cout << min(2LL,cnt) << "\n";
    }
    return 0;
}
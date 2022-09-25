#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL p, q;
        cin >> p >> q;
        if(p % q) cout << p << "\n";
        else{
            LL ans = 1;
            vector<LL> vp;
            LL z = q;
            for(LL i = 2; i * i <= q; i += 1)if(q % i == 0)
                for(vp.push_back(i); q % i == 0; q /= i);
            if(q > 1) vp.push_back(q);
            for(auto x : vp){
                LL y = p;
                while(y % z == 0) y /= x;
                ans = max(ans, y);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
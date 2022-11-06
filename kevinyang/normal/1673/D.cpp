#include <bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int a, int b){
    int v = a*b/(int)__gcd(a,b);
    return v;
}
vector<int> pf(int x){
    int k = x;
    set<int>s;
    vector<int>ret;
    for(int i = 1; i*i<=x; i++){
        if(x%i==0){
            s.insert(i);
            s.insert(x/i);
        }
    }
    for(int nxt: s){
        ret.push_back(nxt);
    }
    return ret;
}
const int mod = (int)1e9+7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int b,q,y;
        cin >> b >> q >> y;
        int lo = b; int hi = b+(y-1)*q;
        int c,r,z;
        cin >> c >> r >> z;
        int low = c; int high = c+(z-1)*r;
        bool f = true;
        if(!(r%q==0)){
            f = false;
        }
        if(lo>low)f = false;
        if(hi<high)f = false;
        if((low-lo)%q!=0)f = false;
        if((hi-high)%q!=0)f = false;
        if(!f){
            cout << "0\n";
            continue;
        }
        if(low-r<lo)f = false;
        if(high+r>hi)f = false;
        if(!f){
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        vector<int>arr = pf(r);
        for(int nxt: arr){
            if(lcm(nxt,q)==r){
                int v = (r/nxt)*(r/nxt);
                ans+=v;
                ans%=mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
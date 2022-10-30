#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if (x%y!=0){
            cout<<x<<endl;
            continue;
        }
        ll res = 1;
        ll bn = x;
        ll by = y;

        for(ll i = 2;i<=sqrt(y);++i){
            if (y%i!=0)continue;
            while(y%i==0){
                y/=i;
                res*=i;
            }
            res/=i;
        }
        y = by;
        for(ll i = 2;i<=sqrt(y);++i){
            if (y%i!=0)continue;
            ll cnt = 0;
            while(y%i==0){
                y/=i;
                ++cnt;
            }
            ll cnt1 = 0;
            while(x%i==0){
                x/=i;
                ++cnt1;
            }
            x = bn;
            for(ll j = 0;j<cnt1-cnt+1;++j)x/=i;
            res = max(res,x);
            x = bn;
        }
        if (y!=1){
            while(x%y==0)x/=y;
            res = max(res,x);
        }

        cout<<res<<endl;
    }

    return 0;

}
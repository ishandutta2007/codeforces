#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 5E5+7;
const ll MOD = 1E9+7;
ll A[DIM],cnt[70],po[70];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    for(ll i = 1;i<=60;++i)po[i] = (po[i-1]*2)%MOD;
    ll t;
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            for(ll bit = 0;bit<60;++bit){
                cnt[bit]+=((A[i]&(1ll<<bit))!=0);
            }
        }
        ll res = 0;
        for(ll i = 1;i<=n;++i){
            ll r1 = 0,r2 = 0;
            for(ll bit = 0;bit<60;++bit){
                if (A[i]&(1ll<<bit)){
                    r1=(r1+n*po[bit])%MOD;
                    r2=(r2+cnt[bit]*po[bit])%MOD;
                }
                else{
                    r1=(r1+cnt[bit]*po[bit])%MOD;
                }
            }
            res=(res+r1*r2)%MOD;
        }

        cout<<res<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll a[100],b[100];
ll c[N];

ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll pow2[100];
int main(){
    ios::sync_with_stdio(0);
    pow2[0]=1;
    for(int i=1;i<100;i++){
        pow2[i]=pow2[i-1]*2%mod;
    }
    ll t;
    cin>>t;
    while(t--){
        for(int i=0;i<60;i++) a[i]=0;
        ll n;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>c[i];
            for(int j=0;j<60;j++) {
                if((c[i]>>j)&1) a[j]++;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll zuo=0,you=0;
            for(int j=0;j<60;j++){
                if((c[i]>>j)&1){
                    zuo=(zuo+pow2[j]*a[j])%mod;
                    you=(you+pow2[j]*n)%mod;
                }else {
                    you=(you+pow2[j]*a[j])%mod;
                }
            }
            ans=(ans+zuo*you)%mod;
        }
        cout<<ans<<endl;
    }
}
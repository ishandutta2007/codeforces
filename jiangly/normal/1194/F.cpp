#include<bits/stdc++.h>
using namespace std;
using LL=long long;
class Solver{
private:
    static constexpr int MAX_N=2e5+5;
    static constexpr int MOD=1e9+7;
    int n;
    LL T;
    int t[MAX_N];
    int fac[MAX_N],facinv[MAX_N];
    int Pow(int a,int b){
        int ans=1;
        while(b>0){
            if(b&1){
                ans=1ll*ans*a%MOD;
            }
            a=1ll*a*a%MOD;
            b>>=1;
        }
        return ans;
    }
public:
    void solve(){
        cin>>n>>T;
        fac[0]=1;
        for(int i=1;i<=n;++i){
            fac[i]=1ll*fac[i-1]*i%MOD;
        }
        facinv[n]=Pow(fac[n],MOD-2);
        for(int i=n-1;i>=0;--i){
            facinv[i]=1ll*facinv[i+1]*(i+1)%MOD;
        }
        for(int i=1;i<=n;++i){
            cin>>t[i];
        }
        int ans=0;
        int sum=0;
        int m;
        bool first=true;
        LL lastT;
        for(int i=1;i<=n;++i){
            T-=t[i];
            if(T<0){
                break;
            }
            if(T>=i){
                ans=(ans+1)%MOD;
            }else{
                if(first){
                    for(int j=0;j<=T;++j){
                        sum=(sum+1ll*fac[i]*facinv[j]%MOD*facinv[i-j])%MOD;
                    }
                    m=T;
                    first=false;
                }else{
                    sum=sum*2%MOD;
                    sum=(sum-1ll*fac[i-1]*facinv[m]%MOD*facinv[i-1-m]%MOD+MOD)%MOD;
                    while(m>T){
                        sum=(sum-1ll*fac[i]*facinv[m]%MOD*facinv[i-m]%MOD+MOD)%MOD;
                        --m;
                    }
                }
                ans=(ans+1ll*sum*Pow(2,MOD-1-i))%MOD;
            }
        }
        cout<<ans<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
class Solver{
private:
    static constexpr int MAX_N=2e5+5;
    static constexpr int MOD=1e9+7;
    int n;
    int l[MAX_N];
    int r[MAX_N];
    int p[MAX_N];
    int x[MAX_N];
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
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>l[i];
        }
        for(int i=1;i<=n;++i){
            cin>>r[i];
            ++r[i];
        }
        for(int i=1;i<=n;++i){
            x[i]=Pow(r[i]-l[i],MOD-2);
        }
        int sum=1;
        for(int i=1;i<=n-1;++i){
            p[i]=1ll*max(0,min(r[i],r[i+1])-max(l[i],l[i+1]))*x[i]%MOD*x[i+1]%MOD;
            sum=(sum+1-p[i])%MOD;
        }
        int ans=1ll*sum*sum%MOD;
        for(int i=1;i<=n-1;++i){
            ans=(ans+1ll*p[i]*(1-p[i]))%MOD;
        }
        for(int i=1;i<=n-2;++i){
            ans=(ans-2ll*p[i]*p[i+1]+2ll*max(0,min(r[i],min(r[i+1],r[i+2]))-max(l[i],max(l[i+1],l[i+2])))*x[i]%MOD*x[i+1]%MOD*x[i+2])%MOD;
        }
        cout<<(ans+MOD)%MOD<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    static constexpr int MAX_N=3e5;
    static constexpr int MOD=998244353;
    int n;
    pair<int,int> s[MAX_N];
    map<pair<int,int>,int> cntp;
    int fac[MAX_N+1];
    int cnta[MAX_N]={};
    int cntb[MAX_N]={};
public:
    Solver(){}
    void solve(){
        cin>>n;
        fac[0]=1;
        for(int i=1;i<=n;++i){
            fac[i]=1ll*fac[i-1]*i%MOD;
        }
        for(int i=0;i<n;++i){
            cin>>s[i].first>>s[i].second;
            ++cnta[s[i].first-1];
            ++cntb[s[i].second-1];
            ++cntp[s[i]];
        }
        sort(s,s+n);
        int ans=fac[n];
        int res=1;
        for(int i=0;i+1<n;++i){
            if(s[i].second>s[i+1].second){
                res=0;
            }
        }
        for(auto [x,y]:cntp){
            res=1ll*res*fac[y]%MOD;
        }
        ans=(ans+res)%MOD;
        int res1=1,res2=1;
        for(int i=0;i<n;++i){
            res1=1ll*res1*fac[cnta[i]]%MOD;
            res2=1ll*res2*fac[cntb[i]]%MOD;
        }
        ans=((ans-res1-res2)%MOD+MOD)%MOD;
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
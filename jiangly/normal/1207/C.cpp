#include<bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr LL LLINF=1e18;
class Solver{
private:
    static constexpr int MAX_N=50;
    int T;
    int n,a,b;
    string s;
    LL dp[2][2];
public:
    Solver(){}
    void solve(){
        cin>>T;
        while(T--){
            cin>>n>>a>>b;
            cin>>s;
            int cur=0;
            dp[0][0]=0;
            dp[0][1]=LLINF;
            for(int i=0;i<n;++i){
                cur^=1;
                if(s[i]=='0'){
                    dp[cur][0]=min(dp[cur^1][0],dp[cur^1][1]+a);
                    dp[cur][1]=min(dp[cur^1][1],dp[cur^1][0]+a)+b;
                }else{
                    dp[cur][0]=LLINF;
                    dp[cur][1]=dp[cur^1][1]+b;
                }
            }
            cout<<dp[cur][0]+1ll*n*a+1ll*(n+1)*b<<endl;
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}
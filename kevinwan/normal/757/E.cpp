#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e6+10;
const ll mod=1e9+7;
ll dp[mn][20];
vector<int>v[mn];
int main(){
    int n;
    scanf("%d",&n);
    dp[0][0]=1;
    for(int i=1;i<20;i++)dp[0][i]=2;
    for(int i=1;i<mn;i++){
        dp[i][0]=1;
        for(int j=1;j<20;j++)dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
    for(int i=2;i<mn;i++)if(!v[i].size()){
        for(int j=i;j<mn;j+=i){
            int num=0,jj=j;
            while(jj%i==0)num++,jj/=i;
            v[j].push_back(num);
        }
    }
    while(n--){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll ans=1;
        for(int x:v[b])ans*=dp[a][x],ans%=mod;
        printf("%lld\n",ans);
    }
}
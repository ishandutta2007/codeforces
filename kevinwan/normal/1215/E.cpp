#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>pos[20];
ll dp[1<<20],kaka[20][20];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll x;
        scanf("%lld",&x);
        pos[x-1].push_back(i);
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++)if(i!=j){
            ll num=0;
            int k,l;
            for(k=0,l=0;k<pos[i].size();k++){
                while(l<pos[j].size()&&pos[j][l]<pos[i][k])l++;
                num+=l;
            }
            kaka[i][j]=num;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<1<<20;i++){
        for(int j=0;j<20;j++)if((i>>j)&1){
            ll hail=0;
            for(int k=0;k<20;k++)if((i>>k)&1){
                hail+=kaka[j][k];
            }
            dp[i]=min(dp[i],dp[i-(1<<j)]+hail);
        }
    }
    printf("%lld",dp[(1<<20)-1]);
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<19)+5,maxk=20;
int i,j,k,n,m,a[maxn],dp[maxn][maxk],Min[maxn][maxk],Max[maxn][maxk],is[maxn];
int main(){
    cin>>n>>m;
    memset(Min,0x3f,sizeof(Min));
    memset(Max,-0x3f,sizeof(Max));
    memset(dp,0x3f,sizeof(dp));
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        is[a[i]]=1;
        Min[a[i]][m]=0;
        Max[a[i]][m]=0;
    }
    for(i=m-1;i>=0;i--){
        for(j=0;j<(1<<m);j++){
            dp[j][i]=min(dp[j][i+1],dp[j^(1<<(m-i-1))][i+1]);
            if(Max[j][i+1]!=-1044266559 && Max[j^(1<<m-i-1)][i+1]!=-1044266559){
                dp[j][i]=min(dp[j][i],Min[j^(1<<(m-i-1))][i+1]+(1<<(m-i-1))-Max[j][i+1]);
                /*
                cerr<<"OK! "<<Min[j^(1<<(m-i-1))][i+1]<<' '<<Max[j][i+1]<<endl;
                if(j&(1<<(m-i-1)))dp[j][i]=min(dp[j][i],Min[j^(1<<(m-i-1))][i+1]+(1<<(m-i-1))-Max[j][i+1]);
                else dp[j][i]=min(dp[j][i],Min[j^(1<<(m-i-1))][i+1]+(1<<(m-i-1))-Max[j][i+1]);
                */
            }
            Min[j][i]=min(Min[j][i+1],Min[j^(1<<(m-i-1))][i+1]+(1<<(m-i-1)));
            Max[j][i]=max(Max[j][i+1],Max[j^(1<<(m-i-1))][i+1]+(1<<(m-i-1)));
            //cerr<<i<<' '<<j<<' '<<dp[j][i]<<' '<<Min[j][i]<<' '<<Max[j][i]<<endl;
        }
    }
    for(i=0;i<(1<<m);i++)printf("%d ",dp[i][0]);
    puts("");
}
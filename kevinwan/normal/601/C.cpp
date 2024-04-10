#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
double dp[100001],ldp[100001],pdp[100001];
int p[101];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(m==1){
        printf("1");
        return 0;
    }
    int sc=0;
    for(int i=1;i<=n;i++)scanf("%d",p+i),sc+=p[i];
    ldp[0]=1;
    fill(pdp,pdp+100001,1);
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof(dp));
        for(int j=1;j<sc;j++){
            dp[j]=pdp[j-1]-((j-m-1>=0)?pdp[j-m-1]:0)-((j-p[i]>=0)?ldp[j-p[i]]:0);
            dp[j]/=(m-1);
        }
        memcpy(ldp,dp,sizeof(dp));
        pdp[0]=ldp[0];
        for(int j=1;j<sc;j++)pdp[j]=pdp[j-1]+ldp[j];
    }
    printf("%.20lf",pdp[sc-1]*(m-1)+1);
}
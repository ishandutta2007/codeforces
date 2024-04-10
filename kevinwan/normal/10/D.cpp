#include <bits/stdc++.h>
using namespace std;
const int mn=510;
int a[mn],b[mn];
int dp[mn][mn],bac[mn][mn];
int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%d",&m);
    for(i=1;i<=m;i++)scanf("%d",b+i);
    b[0]=-1;
    for(i=1;i<=n;i++){
        int op=0,ind=0;
        for(j=0;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            bac[i][j]=j;
            if(b[j]<a[i]){
                if(dp[i-1][j]>op)op=dp[i-1][j],ind=j;
            }
            if(b[j]==a[i])dp[i][j]=op+1,bac[i][j]=ind;
        }
    }
    vector<int>ans;
    int st=0;
    for(i=0;i<=m;i++)if(dp[n][i]>dp[n][st])st=i;
    for(i=n;i;i--){
        if(bac[i][st]!=st)ans.push_back(a[i]);
        st=bac[i][st];
    }
    printf("%d\n",ans.size());
    for(i=ans.size()-1;i>=0;i--)printf("%d ",ans[i]);
}
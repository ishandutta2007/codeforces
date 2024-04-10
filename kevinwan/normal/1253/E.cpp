#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii p[81];
int dp[200101];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second),p[i].first-=p[i].second,p[i].second=p[i].second*2+p[i].first;
    sort(p+1,p+n+1);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int j;
        for(j=0;j+p[i].second<=2*m+10;j++){
            dp[p[i].second+j]=min(dp[p[i].second+j],dp[max(p[i].first-j-1,0)]+j);
        }
        for(j=2*m+9;j>=0;j--)dp[j]=min(dp[j],dp[j+1]);
    }
    printf("%d",dp[m]);
}
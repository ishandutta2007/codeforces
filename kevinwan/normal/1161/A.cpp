#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
int lo[mn],hi[mn];
int main()
{
    int n,k,ans=0,i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)lo[i]=k,hi[i]=-1;
    for(i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        lo[x]=min(lo[x],i);
        hi[x]=max(hi[x],i);
    }
    for(i=1;i<=n;i++)if(lo[i]>hi[i])ans++;
    for(i=1;i<n;i++){
        if(lo[i+1]>hi[i])ans++;
        if(lo[i]>hi[i+1])ans++;
    }
    printf("%d",ans);
}
#include <bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
int p[mn],rp[mn];
int a[mn];
int anc[mn][18],sp[mn][18];
int l[mn];
int main()
{
    int n,m,q,i,j;
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<n;i++)scanf("%d",p+i),rp[p[i]]=i,l[i+1]=m;
    p[n]=p[0];
    for(i=0;i<m;i++)scanf("%d",a+i);
    for(i=m-1;i>=0;i--){
        anc[i][0]=l[p[rp[a[i]]+1]];
        l[a[i]]=i;
    }
    anc[m][0]=m;
    for(i=1;i<18;i++)for(j=0;j<=m;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    for(i=0;i<=m;i++){
        int cur=i;
        for(j=17;j>=0;j--)if((n-1>>j)&1)cur=anc[cur][j];
        sp[i][0]=cur;
    }
    for(i=1;i<18;i++)for(j=0;j+(1<<i-1)<=m;j++)sp[j][i]=min(sp[j][i-1],sp[j+(1<<i-1)][i-1]);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        l--,r--;
        int cur=l,ans=0x3f3f3f3f;
        for(i=17;i>=0;i--)if(cur+(1<<i)<=r+1)ans=min(ans,sp[cur][i]),cur+=1<<i;
        if(ans<=r)printf("1");
        else printf("0");
    }
}
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int cot,v;
}a[200005];
int vis[200005];
int n,k,cnt=0;
bool cmp(node p1,node p2)
{
    return p1.cot<p2.cot;
}
bool check(int m)
{
    int sum=0;
    for(int i=cnt;i>=1;i--)
    {
        sum+=a[i].cot/m;
        if(sum>=k) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&k);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        int s;
        scanf("%d",&s);
        if(!vis[s])
        {
            vis[s]=++cnt;
            a[cnt].v=s,a[cnt].cot=1;
        }
        else a[vis[s]].cot++;
    }
    sort(a+1,a+1+cnt,cmp);
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(check(m)) l=m+1,ans=m;
        else r=m-1;
    }
    for(int i=cnt;i>=1;i--)
    {
        for(int j=1;j<=a[i].cot/ans;j++)
        {
            printf("%d ",a[i].v);k--;
            if(k<=0) break;
        }
        if(k<=0) break;
    }
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],t[N*5];
bool vis[N];
bool check()
{
    if(b[n]==0) return false;
    bool flag=true;
    int pos=n;
    for(int i=b[n];i>=0;i--)
    {
        if(b[pos]!=i) return false;
        pos--;
    }
    return true;
}
int solve2()
{
    for(int i=1;i<=n;i++)
        vis[a[i]]=true;
    int ans=0,pos=1;
    for(int i=1;i<=n;i++)
    {
        while(!vis[i])
        {
            ans++;
            if(b[pos]) vis[b[pos]]=true;
            pos++;
        }
        ans++;
        if(b[pos]) vis[b[pos]]=true;pos++;
    }
    return ans;
}
int solve1()
{
    for(int i=1;i<=n;i++)
        vis[a[i]]=true;
    int ans=0,pos=1;
    for(int i=b[n]+1;i<=n;i++)
    {
        if(!vis[i])
        {
            memset(vis,false,sizeof(vis));
            return solve2();
        }
        if(b[pos]) vis[b[pos]]=true;pos++;
        ans++;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    if(check())
        printf("%d\n",solve1());
    else
        printf("%d\n",solve2());
}
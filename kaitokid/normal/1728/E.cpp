#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll c[300009],pr[300009],tmp[300009],sum;
int vis[300008];
vector<int>dv[300009];
void go(int x)
{
    for(int i=x;i<n;i+=x)
    { ll res=sum+pr[i];
        for(int j=0;j<dv[n-i].size();j++)
        {
            int u=dv[n-i][j];
            if(vis[u]!=x)tmp[u]=0;
            tmp[u]=max(tmp[u],res);
            vis[u]=x;
        }
    }

}
vector<int>q[300009];
int z[300009];
ll ans[300009];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
   // ios::sync_with_stdio(0);
    //cin.tie(0);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
          dv[j].push_back(i);

    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        sum+=y;
        c[i]=x-y;
    }
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=n;i++)pr[i]=pr[i-1]+c[i];
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        q[x].push_back(i);
        z[i]=y;
    }
    for(int i=1;i<=n;i++)
    {
        if(q[i].empty())continue;
        go(i);
        for(int j=0;j<q[i].size();j++)
        {
            int u=q[i][j];
           if(vis[z[u]]==i) ans[u]=tmp[z[u]];
            if((n%z[u])==0)ans[u]=max(ans[u],sum);
            if((n%i)==0)ans[u]=max(ans[u],sum+pr[n]);
        }

    }
    for(int i=0;i<m;i++)
        if(ans[i]==0)printf("-1\n");
        else printf("%lld\n",ans[i]);

    return 0;
}
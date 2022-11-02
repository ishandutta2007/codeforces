#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,a[N],b[N],c[N],f[N],ans[N];
bool vis[N];
vector<int>v[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) vis[i]=false,v[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),vis[b[i]]=true,f[b[i]]=i;
        for(int i=1;i<=m;i++) scanf("%d",&c[i]);
        if(!vis[c[m]])
        {
            printf("NO\n");continue;
        }
        int p;
        for(int i=1;i<=n;i++) if(b[i]==c[m]) p=i;
        for(int i=1;i<=n;i++)
            if(b[i]!=a[i]) v[b[i]].push_back(i);
        if(v[c[m]].size()!=0)
        {
            p=v[c[m]].back();v[c[m]].pop_back();
        }
        for(int i=1;i<=m;i++)
        {
            if(!vis[c[i]]||i==m) ans[i]=p;
            else
            {
                if(v[c[i]].size())
                {
                    ans[i]=v[c[i]].back();
                    v[c[i]].pop_back();
                }
                else ans[i]=f[c[i]];
            }
        }
        bool flag=true;
        for(int i=1;i<=n;i++) if(v[i].size()) flag=false;
        if(!flag) printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=1;i<=m;i++)
                printf(i==m?"%d\n":"%d ",ans[i]);
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,m,i,x,y,j,cnt,ans1;
long long ans2,ans,sum;
int a[200000],b[200000],d[200000],e[200000],f[200000];
bool u[200000];
void add(int x,int y)
{
    cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++) cin>>e[i];
    for (i=1;i<=m;i++)
        {
            cin>>x>>y;
            add(x,y);add(y,x);
        }
    for (i=1;i<=n;i++)
        {
            for (j=d[i];j;j=b[j])
                f[i]+=e[a[j]];
        }
    for (i=1;i<n;i++)
        {
            ans=0;ans1=0;ans2=0;
            for (j=1;j<=n;j++)
               if (u[j]==false)
               if (f[j]!=0)
               if (e[j]>ans)
                  {
                      ans=e[j];ans1=j;ans2=f[j];
                  }
            sum+=ans2;u[ans1]=true;
            for (j=d[ans1];j;j=b[j])
                 f[a[j]]-=e[ans1];
        }
    cout<<sum<<endl;
    return 0;
}
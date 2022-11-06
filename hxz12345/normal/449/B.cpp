#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,i,x,y,z;
long long sum,ans,f[300000];
long long h[800000],e[800000],a[800000],b[800000],c[800000],d[800000],e1[2000000],e2[2000000];
priority_queue< pair < long long ,int >, vector < pair < long long ,int > > ,greater< pair < long long ,int > > > q;
bool u[800000];
void add(int x,int y,int z)
{
    cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    cin>>n>>m>>k;
    for (i=1;i<=m;i++) 
         {
             cin>>x>>y>>z;add(x,y,z);add(y,x,z);
         }
    for (i=1;i<=k;i++)
        {
            cin>>x>>y;add(1,x,y);add(x,1,y);
            e1[i]=x;e2[i]=y;
        }
    for (i=1;i<=n;i++) u[i]=false;
    for (i=2;i<=n;i++) f[i]=100000000000000;
    q.push(make_pair(0,1));
    while (!(q.empty()))
        {
            x=q.top().second;q.pop();
            if (u[x]) continue;u[x]=true;
            for (i=d[x];i;i=b[i])
               if (f[a[i]]>f[x]+c[i])
                  {
                      f[a[i]]=f[x]+c[i];h[a[i]]=1;
                      q.push(make_pair(f[a[i]],a[i]));
                  }
        else if (f[a[i]]==f[x]+c[i]) h[a[i]]++;
        }
    for (i=1;i<=k;i++)
        {
        if (e2[i]>f[e1[i]]) sum++;
        else 
           if (h[e1[i]]>=2)
            {
            h[e1[i]]--;sum++;
            }
        }
    cout<<sum<<endl;
    return 0;
}
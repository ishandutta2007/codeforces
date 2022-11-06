#include<bits/stdc++.h>
using namespace std;
int n,m,i,cnt;
long long x,y,z,f[2000000],c[2000000];
bool u[2000000];
int a[2000000],b[2000000],d[2000000];
priority_queue< pair< long long ,int> , vector< pair<long long ,int> > , greater < pair < long long  , int > > >q;
void add(int x,int y,long long z)
{
    cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;
}
int main()
{
    cin>>n>>m;
    for (i=1;i<=m;i++) 
         {
             cin>>x>>y>>z;
             add(x,y,z*2);add(y,x,z*2);
         }
    for (i=1;i<=n;i++)
          {
              cin>>x;
              add(0,i,x);add(i,0,x);
              f[i]=1000000000000000000;
          }
    f[0]=0;q.push(make_pair(f[0],0));
    while (!(q.empty()))
           {
               x=q.top().second;q.pop();
               if (u[x]==true) continue;u[x]=true;
               for (i=d[x];i;i=b[i])
                   {
                       if (f[a[i]]>f[x]+c[i]) 
                           {
                               f[a[i]]=f[x]+c[i];
                               q.push(make_pair(f[a[i]],a[i]));
                           }
                   }
           }
    for (i=1;i<=n;i++) cout<<f[i]<<" ";
    cout<<endl;
    return 0;
}
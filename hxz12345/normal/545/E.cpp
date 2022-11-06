#include<bits/stdc++.h>
using namespace std;
inline int read()			
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
int cnt,n,m,x,y,z,xx,i,w;
priority_queue< pair<long long ,int>, vector< pair<long long ,int> > , greater<  pair<long long ,int> > > q;
long long ans,f[1000000],e[1000000],a[1000000],b[1000000],c[1000000],d[1000000];
bool u[1000000];
int h[1000000]; 
void add(int x,int y,int z)
{
    cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;
}
int main()
{
    n=read();m=read();
    for (i=1;i<=m;i++)
       {
           x=read();y=read();z=read();
           add(x,y,z);add(y,x,z);
       }
    xx=read();
    for (i=1;i<=n;i++) f[i]=10000000000000000;
    f[xx]=0;q.push(make_pair(0,xx));
    while (!(q.empty()))
         {
             x=q.top().second;q.pop();
             if (u[x]==false) u[x]=true;
             for (i=d[x];i;i=b[i])
                 if (f[a[i]]>f[x]+c[i])
                      {
                          e[a[i]]=i;f[a[i]]=f[x]+c[i];
                          q.push(make_pair(f[a[i]],a[i]));
                      }
            else if (f[a[i]]==f[x]+c[i])
                     if (c[i]<c[e[a[i]]])
                          e[a[i]]=i;
         }
    ans=0;
    for (i=1;i<=n;i++) ans+=c[e[i]];
    printf("%lld\n",ans);
    for (i=1;i<=n;i++)
        if (i!=xx)
              {
                  w++;
               h[w]=(e[i]+1)>>1;
              }
    sort(h+1,h+w+1);
    for (i=1;i<=w;i++) printf("%d ",h[i]);
    return 0;
}
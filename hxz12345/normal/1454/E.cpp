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
bool op[500000],l[500000];
long long ans,oi,n;
long long a[2000000],b[2000000],d[2000000],v[2000000],e1[2000000],e2[2000000];
long long g[500000],gg[500000],e[500000];
long long  T,nn,w,i,x,y,cnt,ww;
bool flag1;
void add(int x,int y)
{
    cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void sc(int x,int fa)
{
if (flag1==false) return ;
int i;
    if (op[x]==false) op[x]=true;
    else
    {
            i=x;
            while (v[i]!=x)
                {
                    l[i]=true;w++;
                    i=v[i];
                }
            flag1=false;w++;
        l[i]=true;
        return ;
    }
     for (int i=d[x];i;i=b[i])
         if (a[i]!=fa)
         {
         v[a[i]]=x;
         sc(a[i],x);
          }
}
void make(int x,int fa)
{
    e[x]=1;
    for (int i=d[x];i;i=b[i])
           if (a[i]!=fa)
              if (l[a[i]]==false)
               {
                   make(a[i],x);e[x]+=e[a[i]];
               }
}
int main()
{
    cin>>T;
    for (;T;T--)
        {
            cin>>n;cnt=0;w=0;
            for (i=1;i<=n;i++) d[i]=0,e[i]=0,v[i]=0;
            for (i=1;i<=n;i++) op[i]=false,l[i]=false;
            for (i=1;i<=n;i++)
                 {
                     cin>>x>>y;
                     add(x,y);add(y,x);
                     e1[i]=x;e2[i]=y;
                 }
            flag1=true;
            sc(1,0);
            if (w==n)
               {
                   printf("%lld\n",n*(n-1));
               }
            else
            {
                   ans=w*(w-1);oi=2*w-1;
                   ans+=(n-w)*oi;ww=0;
                   for (i=1;i<=n;i++)
                       if (l[i]==true)
                           {
                               make(i,0);e[i]--;
                               if (e[i]!=0) {
                                   ww++;g[ww]=e[i];
                               }
                           }
                    for (i=1;i<=ww;i++)
                       ans+=g[i]*(g[i]-1)/2;
                    gg[ww]=g[ww];
                    for (i=ww-1;i>=1;i--) gg[i]=gg[i+1]+g[i];
                    for (i=1;i<=ww-1;i++)
                       ans+=g[i]*gg[i+1]*2;
                    printf("%lld\n",ans);
            }
            
        }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int e3[2100000],e2[2100000],e1[2100000],f[2100000][3],a[2100000],b[2100000],d[2100000],de[2100000],f2[4000000],g[2100000][3];
int l,r,mid,w,ww,n,cnt,ans1,ans2,sum,i,t;
bool o[2100000],ll[2100000],u[2100000];
inline int read()			
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
void add(int x,int y)
{
    cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void sc(int x,int fa)
{
    if (o[x]) return;o[x]=true;
    f[x][1]=x;
    int ans1=0,ans2=0,anss=0,ans=x;
    for (int i=d[x];i;i=b[i])
       if (a[i]!=fa)
          if (ll[a[i]]==false)
           {
           sc(a[i],x);
           if (f[a[i]][1]>ans1)
                {
                ans2=ans1;
               ans1=f[a[i]][1];anss=a[i];
                }
        else if ((f[a[i]][1]>ans2)) ans2=f[a[i]][1];
        if (f[a[i]][1]>ans) ans=f[a[i]][1];
           }
   f[x][1]=max(f[x][1],ans);f[x][0]=ans1;
   g[x][1]=f[x][1];
   int xx=ans2;
   int yy=min(max(x,g[anss][0]),f[anss][1]);
  xx=max(xx,yy);
  g[x][0]=xx;
}
int main()
{
    n=read();
    for (i=1;i<=n;i++)
         {
             e1[i]=read();e2[i]=read();
             w++;e3[w]=e1[i];w++;e3[w]=e2[i];
         }
    sort(e3+1,e3+1+w);ww=0;
    for (i=1;i<=w;i++)
        if (e3[i]!=e3[i-1])
            {
                ww++;e3[ww]=e3[i];
            }
    w=ww;
    for (i=1;i<=n;i++)
         {
             l=1;r=w;ans1=0;
             while (l<=r)
                  {
                      mid=(l+r)/2;
                      if (e3[mid]==e1[i])
                          {
                              ans1=mid;break;
                          }
                    else if (e3[mid]>e1[i]) r=mid-1;
                    else l=mid+1;
                  }
            l=1;r=w;ans2=0;
             while (l<=r)
                  {
                      mid=(l+r)/2;
                      if (e3[mid]==e2[i])
                          {
                              ans2=mid;break;
                          }
                    else if (e3[mid]>e2[i]) r=mid-1;
                    else l=mid+1;
                  }
        e1[i]=ans1;e2[i]=ans2;
        add(ans1,ans2);add(ans2,ans1);
        de[ans1]++;de[ans2]++;
         }
    n=w;w=0;t=1;
     for (i=1;i<=n;i++)
                 if (de[i]==1)
                     {
                     w++;f2[w]=i;
                     }
            while (t<=w)
                {
                if (u[f2[t]]) continue;u[f2[t]]=true;de[f2[t]]--;
                for (i=d[f2[t]];i;i=b[i])
                         {
                         de[a[i]]--;
                         if (de[a[i]]==1)
                             {
                             w++;f2[w]=a[i];
                             }
                         }
                t++; 
                }
    for (i=1;i<=n;i++)
        if (de[i]==2)
            {
            ll[i]=true;
            }
    else if (de[i]>2)   
           {
               printf("-1");
               return 0;
           }
    sum=0;
    for (i=1;i<=n;i++)
        if (ll[i]==true)
           {
               sc(i,0);sum=max(sum,i);
               sum=max(sum,g[i][1]);
           }
   for (i=1;i<=n;i++)
         if (o[i]==false)
             {
             sc(i,0); sum=max(sum,i);
        sum=max(sum,g[i][0]);
          }
    printf("%d\n",e3[sum]);
    return 0;
}
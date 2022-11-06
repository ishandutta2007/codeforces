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
bool op[2000000],u[2000000];
long long z,t,ans,oi,n;
long long MOD;
int f[2000000];
long long a[2000000],b[2000000],d[2000000],v[2000000],e1[2000000],e2[2000000],pw[2000000],r1,r2,anss[2000000];
long long g[2000000],gg[2000000],e[2000000],o[2000000];
int f2[5000000],ans2[2000000];
long long  T,nn,w,x,y,cnt,ww;
int i;
bool flag1;
int find(int x)
{
if (f[x]==x) return x;
f[x]=find(f[x]);return f[x];
}
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
                    w++;
                    i=v[i];
                }
        flag1=false;w++;
        return ;
    }
     for (int i=d[x];i;i=b[i])
         if (a[i]!=fa)
         {
         v[a[i]]=x;
         sc(a[i],x);
          }
}
int main()
{
MOD=1000000007;
            n=read();flag1=true;
            for (i=1;i<=n;i++) f[i]=i;
            for (i=1;i<=n;i++)
                 {
                     x=read();y=i;
                     add(x,y);add(y,x);
                     r1=find(x);r2=find(y);
                     f[r1]=r2;
                     e1[i]=x;e2[x]++;e2[y]++;
                 }
            pw[0]=1;
            for (i=1;i<=n;i++) pw[i]=pw[i-1]*2 % MOD; 
            y=1;t=1;w=0;
            for (i=1;i<=n;i++) anss[find(i)]++;
            for (i=1;i<=n;i++)
                 if (e2[i]==1)
                     {
                     w++;f2[w]=i;
                     }
            while (t<=w)
                {
                if (u[f2[t]]) continue;u[f2[t]]=true;e2[f2[t]]--;
                for (i=d[f2[t]];i;i=b[i])
                         {
                         e2[a[i]]--;
                         if (e2[a[i]]==1)
                             {
                             w++;f2[w]=a[i];
                             }
                         }
                t++; 
                }
           for (i=1;i<=n;i++)
               if (e2[i]==2) ans2[find(i)]++;
            for (i=1;i<=n;i++)
                if ((find(i)==i))
                    {
                       w=ans2[i];
                        z=(pw[anss[i]]-pw[anss[i]-w+1]+MOD) % MOD;
                        y=y*z % MOD;   
                    }
            cout<<y<<endl; 
    return 0;
}
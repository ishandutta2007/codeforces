#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mx=1300000000;
int lst[35999];
int uu[35999];
int sg[101][140000];
int lz[101][140000];
int n,k;

void rfr(int x,int l,int r,int u)
{
    sg[u][x]+=lz[u][x];
    if(l!=r)
    {
        lz[u][2*x+1]+=lz[u][x];
        lz[u][2*x+2]+=lz[u][x];
    }
  lz[u][x]=0;
}
void upd(int qs,int qn,int val,int u,int x=0,int st=0,int en=n)
{
    rfr(x,st,en,u);
    if(qs>en||qn<st)return;
    if(qs<=st&&qn>=en){lz[u][x]+=val;rfr(x,st,en,u);return;}
    int mid=st+(en-st)/2;
    upd(qs,qn,val,u,2*x+1,st,mid);
    upd(qs,qn,val,u,2*x+2,mid+1,en);
    sg[u][x]=min(sg[u][2*x+1],sg[u][2*x+2]);
}
int cal(int qs,int qn,int u,int x=0,int st=0,int en=n)
{
    rfr(x,st,en,u);
    if(qs>en||qn<st)return mx;
    if(qs<=st&&qn>=en)return sg[u][x];
    int mid=st+(en-st)/2;
    return min(cal(qs,qn,u,2*x+1,st,mid),cal(qs,qn,u,2*x+2,mid+1,en));

}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        lst[i]=uu[x];
        uu[x]=i;

    }
     for(int i=1;i<=n;i++)
 {
     if(lst[i]!=0)
     {
         for(int j=0;j<=k;j++)
            upd(0,lst[i]-1,i-lst[i],j);
     }
    upd(i,i,cal(0,0,0),1);
   for(int j=2;j<=min(k,i);j++)
   {
       int rs=cal(0,i-1,j-1);
       upd(i,i,rs,j);

   }
   for(int j=min(k,i)+1;j<=k;j++)
   {
       int rs=mx;
       upd(i,i,rs,j);

   }
 }
  printf("%d",cal(n,n,k));
}
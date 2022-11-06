#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
struct node{
	int x,y;
} b[1001010];
bool vis[1001010];
bool flag;
long long a[20][3010],U[1001010],F[2010][5010],E[3010],final,n,m,i,sta,sum,j,k;
bool cmp(node a,node b){return a.x>b.x;}
void Main(){
	for (i=1;i<=12;i++) U[1<<(i-1)]=i;
    n=read();m=read();
    for (i=1;i<=m;i++) 
    final=(1<<n)-1;
    for (i=1;i<=m;i++) b[i].x=0,b[i].y=i;
	for (i=1;i<=n;i++)
       for (j=1;j<=m;j++)
           a[i][j]=read(),b[j].x=max(b[j].x,(int)a[i][j]);
    sort(b+1,b+m+1,cmp);
    for (i=1;i<=m;i++) vis[i]=false;
    for (i=1;i<=min(n,m);i++) vis[b[i].y]=true;
        for (i=1;i<=m;i++)
           if (vis[i])
       for (sta=1;sta<=final;sta++){F[i][sta]=0;
       	   for (j=1;j<=n;j++)
			   {
			   sum=0; 
       	       for (k=sta;k;k-=k&-k)
       	          sum=sum+a[((U[k&-k])+j-1) % n+1][i];
       	       F[i][sta]=max(F[i][sta],sum);
       	       } 
       }
       flag=false;
    for (i=1;i<=m;i++)
        if (vis[i]){
        	if (flag==false) {
			for (j=1;j<=final;j++) E[j]=F[i][j];flag=true;continue;}
        	for (j=final;j>=1;j--)
        	   for (k=j;k;k=(k-1)&j)
                  E[j]=max(E[j],F[i][k]+E[j^k]);
		}
    printf("%lld\n",E[final]);
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}
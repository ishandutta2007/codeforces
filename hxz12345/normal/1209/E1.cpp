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
long long a[20][3010],U[1001010],F[1010][3010],E[3010],final,n,m,i,sta,sum,j,k;
void Main(){
	for (i=1;i<=12;i++) U[1<<(i-1)]=i;
    n=read();m=read();
    final=(1<<n)-1;
    for (i=1;i<=n;i++)
       for (j=1;j<=m;j++)
           a[i][j]=read();
    for (i=1;i<=m;i++)
       for (sta=1;sta<=final;sta++){F[i][sta]=0;
       	   for (j=1;j<=n;j++)
			   {
			   sum=0; 
       	       for (k=sta;k;k-=k&-k)
       	          sum=sum+a[((U[k&-k])+j-1) % n+1][i];
       	       F[i][sta]=max(F[i][sta],sum);
       	       } 
       }
    for (i=1;i<=final;i++) E[i]=F[1][i];
    for (i=2;i<=m;i++)
       for (j=final;j>=1;j--)
           for (k=j;k;k=(k-1)&j)
              E[j]=max(E[j],F[i][k]+E[j^k]);
    printf("%lld\n",E[final]);
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}
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
long long l,r,C[18][1<<17],B[18][1<<17],a[1<<17],ans,i,j;
void Main(){
	l=read();r=read();
	for (i=l;i<=r;i++) a[i]=read();
	for (i=l;i<=r;i++)
	   for (j=0;j<=16;j++)
	       if (i==0) C[j][0]=(a[i]>>j&1);
	       else C[j][i]=C[j][i-1]+(a[i]>>j&1);
	ans=0;
	for (i=0;i<=16;i++)
	    if (C[i][r]+B[i][r]==r-l+1) ans+=(1<<i);
    printf("%lld\n",ans);
	return ;
}
int main()
{
	for (i=0;i<=(1<<17)-1;i++)
	    for (j=0;j<=16;j++)
	        if (i==0) B[j][i]=(i>>j&1);
	        else B[j][i]=B[j][i-1]+(i>>j&1);
	int Testing=read();
	for (;Testing;Testing--) Main();
 return 0;
}
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
#define MOD 1000000007
long long ttt,tt,tot,ans,j,n,m,k,t,i,S2[5010][5010],pw1[200100],pw2[201010],vv,A,B;
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	    if (y&1) ans=ans*x % p;return ans;
}
void Main(){
	n=read();m=2;k=read();
	if (m==1){printf("%lld\n",pow(n,k,MOD));return ;}
	B=m/2;A=m-B;t=A*pow(B,MOD-2,MOD) % MOD;
	vv=pow(B,n,MOD);
	pw1[0]=1;pw2[0]=1;
	for (i=1;i<=k;i++) pw1[i]=pw1[i-1]*t % MOD;
	ttt=pow(t+1,n,MOD);
	tt=pow(t+1,MOD-2,MOD);
	for (i=1;i<=k;i++) pw2[i]=pw2[i-1]*tt % MOD;
	ans=0;tot=1;
	for (i=0;i<=k;i++)
	    if (i<=n) 
		   {
		   ans=(ans+pw1[i]*ttt % MOD*pw2[i] % MOD*tot % MOD*S2[k][i]) % MOD;
		   tot=tot*(n-i) % MOD;
	       }
	printf("%lld\n",ans*pow(B,n,MOD) % MOD);
	return ;
}
int main()
{
	S2[0][0]=1;
	for (i=1;i<=5000;i++)
	   for (j=1;j<=i;j++)
	       S2[i][j]=(S2[i-1][j-1]+j*S2[i-1][j]) % MOD;
	int Testing=1;
	for (;Testing;Testing--) Main();
return 0;
}
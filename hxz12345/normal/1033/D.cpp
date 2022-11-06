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
map<long long,long long> fre,Gw;
map<long long,bool>Gu;
bool Gq[1001010];
long long c[1001010],t,w,j,i,x,G1,G2,G3,inv[1001010],tot,n,MOD,a[1001010],b[1001010];
long long gcd(long long x,long long y){
	if (y==0) return x;return gcd(y,x % y);
}
long long nmsl(long long x){
	long long l,r,mid;
	l=1;r=1259921;
	while (l<=r){
		mid=(l+r)>>1;
		if (mid*mid*mid==x) return mid;
		if (mid*mid*mid>x) r=mid-1;
		else l=mid+1;
	}return 0;
}
int main()
{
	n=read();tot=1;MOD=998244353;
	inv[1]=1;
	for (i=2;i<=1000000;i++) inv[i]=(MOD-MOD/i)*inv[MOD % i] % MOD;
	for (i=1;i<=n;i++) {
		x=read();
		G1=sqrt(x);G2=nmsl(x);G3=sqrt(sqrt(x));
			if (G3*G3*G3*G3==x) {tot=tot*inv[fre[G3]+1] % MOD;b[++t]=G3;fre[G3]+=4;tot=tot*(fre[G3]+1) % MOD;}
		else if (G1*G1==x) {tot=tot*inv[fre[G1]+1] % MOD;b[++t]=G1;fre[G1]+=2;tot=tot*(fre[G1]+1) % MOD;}else
		if (G2*G2*G2==x) {tot=tot*inv[fre[G2]+1] % MOD;b[++t]=G2;fre[G2]+=3;tot=tot*(fre[G2]+1) % MOD;}
	else{
			a[++w]=x;
		}
	}
	for (i=1;i<w;i++)
	   for (j=i+1;j<=w;j++)
	      if (a[i]!=a[j])
	      if (gcd(a[i],a[j])!=1)
	        b[++t]=gcd(a[i],a[j]);
	sort(b+1,b+t+1);t=unique(b+1,b+t+1)-b-1;
	for (i=1;i<=w;i++) c[i]=a[i];
	for (j=1;j<=t;j++)
	   for (i=1;i<=w;i++)
	       if (a[i] % b[j]==0){
	       	   tot=tot*inv[fre[b[j]]+1] % MOD;
	       	   fre[b[j]]++;
	       	   tot=tot*(fre[b[j]]+1) % MOD;
	       	   a[i]/=b[j];
	       	   Gq[i]=true;
		   }
	for (i=1;i<=w;i++) Gw[a[i]]++;
	for (i=1;i<=w;i++)
	    if (a[i]!=1)
		   if ((a[i]==c[i])&&(Gu[a[i]]==false)) tot=tot*(Gw[a[i]]+1) % MOD*(Gw[a[i]]+1) % MOD,Gu[a[i]]=true;
		   else if ((a[i]!=c[i])&&(Gu[a[i]]==false)) tot=tot*(Gw[a[i]]+1) % MOD,Gu[a[i]]=true;
		printf("%lld\n",tot);
return 0;
}
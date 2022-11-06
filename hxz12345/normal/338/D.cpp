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
long long n,i,m,K;
__int128 c[1001010],ansa,ans,a[1001010],b[1001001],A,B,V,Va,Vb;
void exgcd(__int128 x,__int128 y){
	if (y==0){A=1;B=0;return ;}
	exgcd(y,x % y);long long C=A;A=B;B=C-(x/y)*B;
}
int main()
{
	n=read();m=read();K=read();ansa=1;
	for (i=1;i<=K;i++) {
		c[i]=read();
		if (c[i]>m){puts("NO");return 0;}
		if (ansa/__gcd(ansa,c[i])>n/c[i]) {puts("NO");return 0;}
		ansa=ansa/__gcd(ansa,c[i])*c[i];
	}
	for (i=1;i<=K;i++) {a[i]=1-i;b[i]=c[i];a[i]%=b[i];a[i]=(a[i]+b[i]) % b[i];swap(a[i],b[i]);}
	if (K==1) ans=b[1];
	for (i=2;i<=K;i++){
		if (b[i-1]>b[i]) swap(a[i],a[i-1]),swap(b[i],b[i-1]);
		exgcd(a[i-1],a[i]);B=-B;V=a[i]/__gcd(a[i],a[i-1])*a[i-1];
		A=A*((b[i]-b[i-1])/__gcd(a[i],a[i-1]));B=B*((b[i]-b[i-1])/__gcd(a[i],a[i-1]));
		Vb=a[i-1]/__gcd(a[i],a[i-1]);
		if (B>=0) B=B % Vb;else B=B+((-B-1)/Vb+1)*Vb;
		if (a[i]*B+b[i]>m){puts("NO");return 0;}
		if (i==K) {ans=a[i]*B+b[i];break;}
		b[i]=a[i]*B+b[i];a[i]=V;b[i]%=a[i];
		}
	if (ans+K-1>m){puts("NO");return 0;}
    for (i=1;i<=K;i++)
        if (__gcd(ansa,ans+i-1)!=c[i]){
        	puts("NO");return 0;
		}
    puts("YES");
return 0;
}
/*

*2900 is too hard for me  
*/
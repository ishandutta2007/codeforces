#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define ep 1e-7
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}//long dou    Lf //
#define N 170009
long long n,b[N],ss,f[N];
double a[N];
int main()
{//ab abs fabs   ()
//	cerr<<int(-6.99999);
	n=read();for(int i=1;i<=n;++i) scanf("%lf",a+i);
	for(int i=1;i<=n;++i)if(a[i]<-ep)b[i]=(int)(a[i]-1+ep);else b[i]=(int)(a[i]+ep);
	for(int i=1;i<=n;++i)if(abs(a[i]-b[i])<ep)f[i]=1;
	for(int i=1;i<=n;++i)ss+=b[i];
	ss=-ss;
	for(int i=1;i<=n;++i)if(ss&&!f[i]){
		--ss;
		printf("%lld\n",b[i]+1);
	}else printf("%lld\n",b[i]);
}
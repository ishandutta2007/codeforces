#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define MO 1000000007
#define N 4009400
int T,x,n,a[N],u,m;
char s[N];

int main()
{
	int fl;
	T=read();
	while(T--){
		x=read(); 
		scanf("%s",s+1);
		n=strlen(s+1); fl=0;
		for(int i=1;i<=n;++i)a[i]=s[i]-48;
		for(int i=1;i<=x;++i){
			if(a[i]==1)continue;
			u=a[i]-1;
			if(n<=x&&!fl){
				m=n;
				for(int t=1;t<=u;++t)
				for(int j=i+1;j<=n;++j){
					a[++m]=a[j];
				}
				n=m;
			} else {
				fl=1;
				n=(u*(n-i)%MO+n)%MO;
				n=(n+MO)%MO;
			}
		}
		printf("%d\n",n);
	} 
}
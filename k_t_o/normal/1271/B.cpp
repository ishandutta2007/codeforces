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
char s[999];int n,a[999],st[9999],tt;
int main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)a[i]=s[i]=='B';
//	for(int i=1;i<=n;++i)A+=a[i];B=n-A;
	
	for(int i=1;i<n;++i){
		if(a[i]){
			st[++tt]=i;
			a[i]^=1;
			a[i+1]^=1;
		}
	}
	if(!a[n]){
		printf("%d\n",tt);for(int i=1;i<=tt;++i)printf("%d ",st[i]);return 0;
	}
	for(int i=n-1;i>1;--i){
		if(!a[i]){
			st[++tt]=i-1;
			a[i]^=1;
			a[i-1]^=1;
		}
	}
	if(a[1]){
		printf("%d\n",tt);for(int i=1;i<=tt;++i)printf("%d ",st[i]);return 0;
	}
	puts("-1");
}
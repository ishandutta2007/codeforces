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
long long n,m,k,g;
int main()
{
	n=read(); m=read(); scanf("%lld",&k);
	if(k<n){
		cout<<k+1<<' '<<1<<endl;
		return 0;
	}
	k-=n;
	g=k/((m-1)*2);
	k-=(long long)g*(m-1)*2;
	if(k<m-1){
		cout<<n-g-g<<' '<<k+2<<endl;
		return 0;
	}
	cout<<n-g-g-1<<' '<<m-(k-m+1)<<endl;
}
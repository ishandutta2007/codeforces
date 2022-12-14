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
int a[10005],T,n,l,r,Ans;char s[10005];
int main()
{
	T=read();
	while(T--){
		n=read();scanf("%s",s+1);
		for(int i=1;i<=n;++i)a[i]=s[i]-48;
		l=r=0;
		for(int i=1;i<=n;++i)if(a[i]){
			l=i; break;
		}
		for(int i=n;i;--i)if(a[i]){
			r=i; break;
		}
		Ans=n;
		if(l)Ans=max(Ans,n-l+1+n-l+1);
		if(r)Ans=max(Ans,r+r);
		cout<<Ans<<endl;
	}
}
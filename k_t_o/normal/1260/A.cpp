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
long long T,c,s,Ans,k,u;
int main()
{
	T=read();
	while(T--){
		c=read(); s=read(); c=min(c,s);
		k=s/c;
		u=s-k*c;
		Ans=k*k*(c-u)+u*(k+1)*(k+1);
		cout<<Ans<<endl;
	}
}
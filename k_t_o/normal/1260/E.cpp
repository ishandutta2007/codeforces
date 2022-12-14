#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0,f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret*f;
}
#define N 1090030
int n,fl,a[N],cc,op;
multiset<int>S;
long long Ans;
int main()
{
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]==-1){
			a[i]=0;
			fl=1;
		}
		if(!fl)a[i]=0;
	}
	
	cc=log2(n+0.1); op=1; --cc;
	for(int i=n;i>1;--i){
		S.insert(a[i]);
		if(S.size()==op){
			op+=1<<cc; --cc; --op;
			Ans+=*S.begin();
			S.erase(S.begin());
		}
	} 
	printf("%lld\n",Ans);
}
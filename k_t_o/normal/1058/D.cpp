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
long long n,m,k,a,aa,f[205],g[205],tt,s,nn,mm;

void dfs(int p, long long r)
{
	if(r>n)return;
	if(aa/r<=m){
		puts("YES");
		puts("0 0");
		printf("%d 0\n",r);
		printf("0 %d\n",aa/r);
		exit(0);
	}
	if(p>tt)return;
	dfs(p+1,r);
	for(int i=1;i<=g[p];++i){
		r*=f[p];
		dfs(p+1,r);
	}
}
inline void sol()
{
	nn=n; mm=m;
		for(int i=2;i<=32000;++i){
			while(nn%i==0)nn/=i;
			while(mm%i==0)mm/=i;
			s=0;while(a%i==0){
				a/=i;
				++s;
			}
			if(s){
				f[++tt]=i;
				g[tt]=s;
			}
		}
		if(a>1){
			if(nn>1){
				f[++tt]=nn;
				g[tt]=1;
				a/=nn;
			}
		}
		if(a>1){
			if(mm>1){
				f[++tt]=mm;
				g[tt]=1;
				a/=mm;
			}
		}
}

int main()
{
	n=read(); m=read(); k=read();
	if(n*m*2%k!=0)goto llll;
	aa=a=n*m*2/k;
	sol();
	dfs(1,1);
	llll:puts("NO");
}
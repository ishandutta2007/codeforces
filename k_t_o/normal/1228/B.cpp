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
#define N 1005
#define MO 1000000007
int h,w,f[N][N],c[N],r[N],s;
int main()
{
	h=read(); w=read();
	for(int i=1;i<=h;++i){
		r[i]=read();
		for(int j=1;j<=r[i];++j)f[i][j]=2;
		f[i][r[i]+1]=1;
	}
	for(int i=1;i<=w;++i){
		c[i]=read();
		for(int j=1;j<=c[i];++j){
			if(f[j][i]==1){
				puts("0");
				exit(0);
			}
			f[j][i]=2;
		}
		if(f[c[i]+1][i]==2){
			puts("0");
			exit(0);
		}
		f[c[i]+1][i]=1;
	}
	s=1;
	for(int i=1;i<=h;++i)
	for(int j=1;j<=w;++j)if(!f[i][j])s=(s<<1)%MO;
	cout<<s;
}
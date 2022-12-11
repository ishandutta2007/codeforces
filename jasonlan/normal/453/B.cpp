#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=101;
int n;
int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[maxn][1<<16],b[maxn][1<<16],fac[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=2;i<=58;++i)
		for(register int j=i,k=0;k<16;++k)
			if(!(j%prime[k])){
				fac[i]|=1<<k;
				while(!(j%prime[k]))j/=prime[k];
			}
	for(register int i=1,x;i<=n;++i){
		x=read();
		for(register int j=0;j<1<<16;++j)
			f[i][j]=f[i-1][j]+x-1,b[i][j]=1;
		for(register int j=2;j<=(x<<1)-1;++j){
			if(j==59)break;
			int d=fac[j]^((1<<16)-1);
			for(register int k=d,g=abs(x-j);~k;--k){
				k=k&d;
				if(f[i-1][k]+g<f[i][k|fac[j]]){
					f[i][k|fac[j]]=f[i-1][k]+g;
					b[i][k|fac[j]]=j;
				}
			}
		}
	}
	int pos=0;
	for(register int i=1;i<1<<16;++i)
		if(f[n][i]<f[n][pos])pos=i;
	for(register int i=n;i;--i){
		b[0][i]=b[i][pos];
		pos^=fac[b[0][i]];
	}
	for(register int i=1;i<=n;++i)
		printf("%d ",b[0][i]);
	return 0;
}
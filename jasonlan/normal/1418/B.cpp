#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=201000,INF=1e7;
int n;
int f[maxn],g[maxn];
int l[maxn],lp;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();lp=0;
		for(register int i=1;i<=n;++i)
			f[i]=read();
		for(register int i=1;i<=n;++i)
			if(!(g[i]=read()))l[++lp]=f[i];
		sort(l+1,l+1+lp);
		for(register int i=1,p=lp+1;i<=n;++i)
			if(!g[i])f[i]=l[--p];
		printf("%d",f[1]);
		for(register int i=2;i<=n;++i)
			printf(" %d",f[i]);
		putchar('\n');
	}
	return 0;
}
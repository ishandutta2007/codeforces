#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=201000,INF=1e7;
int n;
int f[maxn],g[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		g[0]=0;f[0]=g[1]=INF;
		f[1]=read();
		for(register int i=2,x,pre=f[1];i<=n;++i){
			x=read();
			g[i]=min(f[i-1],f[i-2]);
			f[i]=min(g[i-1]+x,g[i-2]+x+pre);
			pre=x;
		}
		printf("%d\n",min(g[n],f[n]));
	}
	return 0;
}
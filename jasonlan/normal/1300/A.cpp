#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ls(p) (son[0][p])
#define rs(p) (son[1][p])
#define mid ((l+r)>>1)
using namespace std;
int n,m,t;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		t=m=0;
		for(register int i=1,x;i<=n;++i){
			x=read();
			m+=x;t+=!x;
		}
		if(!(m+t))++t;
		printf("%d\n",t);
	}
	return 0;
}
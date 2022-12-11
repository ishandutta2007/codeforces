#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=450200;
int n,g,s,b,a[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int findnxt(int p){
	for(register int i=20,w=a[p];~i;--i){
		p+=1<<i;
		if(p>n||a[p]!=w)p-=1<<i;
	}
	return p;
}
int main(){
	for(register int T=read(),x;T;--T){
		n=read();
		memset(a,-1,sizeof(a));
		for(register int i=1;i<=n;++i)
			a[i]=read();
		g=findnxt(1);
		s=g;
		while(s-g<=g&&s<=n>>1)
			s=findnxt(s+1);
		b=s;
		while((x=findnxt(b+1))<=n>>1)
			b=x;
		if(s-g<=g||b-s<=g||b>n>>1)puts("0 0 0");
		else printf("%d %d %d\n",g,s-g,b-s);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=101000;
int n,a[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read(),pre,p;T;--T){
		n=read();
		pre=read();
		bool flag=false;
		for(register int i=2;i<=n;++i){
			p=read();
			if(p>=pre)flag=true;
			pre=p;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
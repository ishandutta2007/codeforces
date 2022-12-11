#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read(),x,y,k;T;--T){
		x=read();y=read();k=read();
		--x;
		long long need=1ll*y*k+k-1;
		printf("%lld\n",(need+x-1)/x+k);
	}
	return 0;
}
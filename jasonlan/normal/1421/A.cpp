#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read(),x,y;T;--T){
		x=read();y=read();
		printf("%d\n",(x^y));
	}
	return 0;
}
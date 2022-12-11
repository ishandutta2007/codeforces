#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();m=read();
		while(n--)m-=read();
		puts(!m?"YES":"NO");
	}
	return 0;
}
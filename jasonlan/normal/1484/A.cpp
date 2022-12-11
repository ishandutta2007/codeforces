#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=301100;
int n,m;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		n=read();m=read();
		printf("%d\n",1+(m-1)*n+(n-1));
	}
	return 0;
}
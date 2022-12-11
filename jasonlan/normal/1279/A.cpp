#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=200100,mod=1e9+7;
int r,g,b;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int main(){
	for(register int T=read();T;--T){
		r=read();g=read();b=read();
		if(r>g+b+1||g>r+b+1||b>r+g+1)puts("No");
		else puts("Yes");
	}
	return 0;
}
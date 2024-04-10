#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1001000;
int mini,maxi,n,T;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	T=read();
	while(T--){
		n=read();
		maxi=0;mini=1000000000;
		for(register int i=0,x;i<n;++i){
			x=read();
			maxi=max(x,maxi);
			mini=min(x,mini);
		}
		if(maxi==mini)printf("%d\n",n);
		else printf("1\n");
	}
	return 0;
}
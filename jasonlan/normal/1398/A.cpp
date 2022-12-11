#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,mi1,mi2,ma;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	int t=read();
	while(t--){
		n=read();mi1=read();mi2=read();
		for(register int i=3;i<n;++i)
		    read();
		if(mi1+mi2<=read())printf("1 2 %d\n",n);
		else puts("-1");
	}
	return 0;
}
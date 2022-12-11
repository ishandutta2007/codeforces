#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long S,a1,n;
inline long long read(){
    long long res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=0;i<n;++i)
		S+=read();
	a1=((S<<1)/n-n+1)>>1;
	S-=((a1<<1)+n-1)*n>>1;
	for(register int i=0;i<n;++i,S-=!(!S))
		printf("%lld ",a1+i+(!(!S)));
	return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,x,y;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	for(register int T=read();T;--T){
		n=read();x=read();y=read();
		printf("%d",x);
		--n;
		for(register int i=1;i<=y-x;++i){
			if((y-x)%i||(y-x)/i>n)continue;
			for(register int j=x+i;j<=y;j+=i,--n)
				printf(" %d",j);
			for(register int j=x-i;j>0&&n;j-=i,--n)
				printf(" %d",j);
			for(register int j=y+i;n;j+=i,--n)
				printf(" %d",j);
		}
		putchar('\n');
	}
	return 0;
}
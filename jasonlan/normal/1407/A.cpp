#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c0,c1;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return res;
}
void output(int x,int p){
	printf("%d\n",p);
	while(p--)printf("%d ",x);
	putchar('\n');
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		c0=c1=0;
		for(register int i=1;i<=n;++i)
			!read()?++c0:++c1;
		if(c1>c0){
			if((n>>1)&1)output(1,(n+2)>>1);
			else output(1,n>>1);
		}
		else output(0,n>>1);
			
	}
    return 0;
}
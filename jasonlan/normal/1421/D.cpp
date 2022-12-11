#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long x,y;
int c1,c2,c3,c4,c5,c6;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		x=read();y=read();
		c1=read();c2=read();c3=read();c4=read();c5=read();c6=read();
		for(register int i=0;i<15;++i){
			c1=min(c1,c2+c6);
			c2=min(c2,c1+c3);
			c3=min(c3,c2+c4);
			c4=min(c4,c3+c5);
			c5=min(c5,c4+c6);
			c6=min(c6,c1+c5);
		}
		if(x<=0&&y<=0)
			printf("%lld\n",x>=y?-x*c4-(y-x)*c5:-y*c4-(x-y)*c3);
		else if(x>=0&&y>=0)
			printf("%lld\n",x<=y?x*c1+(y-x)*c2:y*c1+(x-y)*c6);
		else if(x>=0&&y<=0)
			printf("%lld\n",x*c6-y*c5);
		else
			printf("%lld\n",-x*c3+y*c2);
	}
	return 0;
}
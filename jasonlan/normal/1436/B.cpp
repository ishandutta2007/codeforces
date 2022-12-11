#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
bool flag;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void output(char ch){
	if(flag)putchar(' ');
	putchar(ch);
	flag=true;
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		for(register int i=1;i<n;++i){
			flag=false;
			for(register int j=1;j<i;++j)
				output('0');
			output('1');
			output('1');
			for(register int j=i+2;j<=n;++j)
				output('0');
			puts("");
		}
		flag=false;
		output('1');
		for(register int i=2;i<n;++i)output('0');
		output('1');
		puts("");
	}
	return 0;
}
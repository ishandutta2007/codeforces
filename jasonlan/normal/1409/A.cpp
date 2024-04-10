#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	for(register int T=read(),a,b;T;--T){
		a=read();b=read();
		if(a<b)swap(a,b);
		printf("%d\n",(a-b+9)/10);
	}
	return 0;
}
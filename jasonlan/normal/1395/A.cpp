#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1001000;
int T,a,b,c,d;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	T=read();
	while(T--){
		a=read();b=read();c=read();d=read();
		bool can_ch=(a&&b&&c);
		int odd=(a&1)+(b&1)+(c&1)+(d&1);
		if(odd<=1||((odd==3||odd==4)&&can_ch))
			puts("YES");
		else puts("NO");
	}
	return 0;
}
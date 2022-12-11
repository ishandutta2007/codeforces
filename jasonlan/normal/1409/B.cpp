#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,a,b,x,y;
long long ans1,ans2;
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
		a=read();b=read();x=read();y=read();n=read();
		if(a-x+b-y<=n){
			printf("%lld\n",(long long)x*y);continue;
		}
		if(a-x<n)
			ans1=(long long)x*(b-(n-(a-x)));
		else
			ans1=(long long)b*(a-n);
		if(b-y<n)
			ans2=(long long)y*(a-(n-(b-y)));
		else
			ans2=(long long)a*(b-n);
		printf("%lld\n",min(ans1,ans2));
	}
	return 0;
}
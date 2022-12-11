#include<iostream>
#include<cstdio>
using namespace std;
inline long long read(){
	long long res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		long long p=read(),a=read(),b=read(),c=read();
		if(p%a>0)a=(p/a+1)*a;
		else a=p;
		if(p%b>0)b=(p/b+1)*b;
		else b=p;
		if(p%c>0)c=(p/c+1)*c;
		else c=p;
		long long ans=min(a-p,min(b-p,c-p));
		printf("%lld\n",ans);
	}
	return 0;
}
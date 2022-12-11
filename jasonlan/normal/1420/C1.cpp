#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=301000;
int n,q;
long long ans;
int a[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void process(){
	n=read();read();
	for(register int i=1;i<=n;++i)
		a[i]=read();
	a[n+1]=0;
	ans=0;
	for(register int i=1;i<=n;++i)
		if(a[i]-a[i-1]>0)ans+=a[i]-a[i-1];
	printf("%lld\n",ans);
}
int main(){
	for(register int T=read();T;--T)
		process();
	return 0;
}
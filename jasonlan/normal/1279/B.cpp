#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=101000;
int n,s;
int a[maxn],mxipos;
long long sum;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int main(){
	for(register int T=read(),ans;T;--T){
		n=read();s=read();
		sum=mxipos=ans=0;
		for(register int i=1;i<=n;++i){
			a[i]=read();
			sum+=a[i];
			if(a[mxipos]<a[i])mxipos=i;
			if(sum-a[mxipos]<=s)ans=mxipos;
		}
		if(sum<=s)puts("0");
		else printf("%d\n",ans);
	}
	return 0;
}
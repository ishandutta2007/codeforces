#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=5010,mod=998244353,pm=828542813;
int n,f;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	n=read();
	for(register int i=1,x;i<=n;++i){
		x=read();
		f=1ll*(f+1)*qpow(x,mod-2)%mod*100%mod;
	}
	printf("%d",f);
    return 0;
}
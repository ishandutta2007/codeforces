#include<iostream>
#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=31;
int n,cnt[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read(),p;T;--T){
		n=read();
		while(n--){
			p=read();
			for(register int i=30;~i;--i)
				if(p>>i){++cnt[i];break;}
		}
		long long ans=0;
		for(register int i=30;~i;--i)
			ans+=1ll*cnt[i]*(cnt[i]-1)/2,cnt[i]=0;
		printf("%lld\n",ans);
	}
	return 0;
}
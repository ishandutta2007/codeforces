#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1000010,mod=998244353;
int n,ans;
int sum[maxn];
vector<int> v[maxn];
int qmod(int x){
	return x>=mod?x-mod:x;
}
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
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
	for(register int i=1;i<=n;++i)
		for(register int j=read(),x;j;--j){
			v[i].push_back(x=read());
			++sum[x];
		}
	for(register int i=1;i<=n;++i){
		int res=0;
		for(register int j=0;j<v[i].size();++j)
			res=qmod(res+1ll*sum[v[i][j]]*qpow(n,mod-2)%mod);
		ans=qmod(ans+1ll*res*qpow(v[i].size(),mod-2)%mod);
	}
	printf("%lld\n",1ll*ans*qpow(n,mod-2)%mod);
	return 0;
}
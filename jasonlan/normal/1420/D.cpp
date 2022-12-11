#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=601000,mod=998244353;
int n,k,ans;
int p[maxn],mp[maxn];
struct note{
	int p;bool g;
	bool operator <(note b)const{
		return (p^b.p)?(p<b.p):(g>b.g);
	}
}ex[maxn];
int fpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
void reset(){
	p[0]=1;
	for(register int i=1;i<=n;++i)
		p[i]=1ll*p[i-1]*i%mod;
	mp[n]=fpow(p[n],mod-2);
	for(register int i=n-1;~i;--i)
		mp[i]=1ll*mp[i+1]*(i+1)%mod;
}
int C(int x,int y){
	if(y>x)return 0;
	return 1ll*p[x]*mp[y]%mod*mp[x-y]%mod;
}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
signed main(){
	n=read();k=read();
	reset();
	n<<=1;
	for(register int i=1;i<=n;++i)
		ex[i].p=read(),ex[i].g=i&1;
	sort(ex+1,ex+1+n);
	for(register int i=1,cnt=0;i<=n;++i){
		if(ex[i].g)++cnt;
		else ans=(ans+C(cnt-1,k-1))%mod,--cnt;
	}
	printf("%d",ans);
	return 0;
}
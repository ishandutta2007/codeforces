#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2530,mod=2520;
int n;
int dig[maxn];
ll f[19][maxn][1<<9];
inline ll read(){
    ll res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
ll dfs(int sum,int dep,int lcm,bool mi){
	if(!dep){
		for(register int i=2;i<=9;++i)
			if((lcm>>(i-1))&1)
				if(sum%i)return 0;
		return 1;
	}
	if(!mi&&~f[dep][sum][lcm])return f[dep][sum][lcm];
	ll ret=0;
	for(register int i=0,j=mi?dig[dep]:9;i<=j;++i){
		if(!i)ret+=dfs(sum*10%mod,dep-1,lcm,mi&(i==j));
		else ret+=dfs((sum*10+i)%mod,dep-1,lcm|(1<<(i-1)),mi&(i==j));
	}
	if(!mi)f[dep][sum][lcm]=ret;
	return ret;
}
ll pro(ll x){
	int len=0;
	while(x)dig[++len]=x%10,x/=10;
	return dfs(0,len,1,1);
}
int main()
{
	int T=read();
	memset(f,-1,sizeof(f));
	while(T--){
		ll l=read(),r=read();
		printf("%I64d\n",pro(r)-pro(l-1));
	}
	return 0;
}
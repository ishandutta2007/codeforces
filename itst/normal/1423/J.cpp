#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
ll f[63][9];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		ll m=gi();
		memset(f,0,sizeof f);
		f[0][0]=1;f[0][1]=-1;
		for(int i=0;i<=60;++i){
			int d=m>>i&1;ll s=0;
			if(i%10==0)for(int j=0;j<8;++j)f[i][j]%=mod;
			for(int j=0;j<8;++j){
				s+=f[i][j];
				f[i+1][j+(j+d&1)>>1]+=s;
				f[i+1][j+(j+d&1)+8>>1]-=s;
			}
		}
		printf("%lld\n",f[61][0]%mod);
	}
	return 0;
}
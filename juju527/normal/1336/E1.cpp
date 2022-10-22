//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector
#define eb emplace_back
using namespace std;
const int maxm=45,mod=998244353;
int n,m,c;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void add(int &x,int y){x=add(x+y);return ;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
int f[maxm];
ll p[maxm];
bool ins(ll x){
	for(int i=m-1;i>=0;i--){
		if(!((x>>i)&1))continue;
		if(!p[i]){p[i]=x;return 1;}
		x^=p[i];
	}
	return 0;
}
void solve(){
	for(int i=0;i<m;i++){
		if(!p[i])continue;
		for(int j=i+1;j<m;j++)if((p[j]>>i)&1)p[j]^=p[i];
	}
	return ;
}
const int maxs=(1<<20)+5;
ll st[maxs];
int dp[maxm][maxs],buf[maxm][maxs];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)c+=ins(read());
	solve();
	int w=power(2,n-c);
	if(c<=20){
		vec<ll> a;a.clear();
		for(int i=0;i<m;i++)if(p[i])a.eb(p[i]);
		int S=(1<<c)-1;
		for(int s=0;s<=S;s++){
			ll aux=(s==0)?0:(st[s^(s&-s)]^a[__builtin_ctz(s)]);
			st[s]=aux;
			add(f[__builtin_popcountll(aux)],w);
		}
	}
	else{
		vec<int> a;a.clear();
		for(int i=0;i<m;i++)if(!p[i])a.eb(i);
		int S=(1<<(m-c))-1,num=0;
		dp[0][0]=w;
		for(int i=0;i<m;i++){
			if(!p[i])continue;
			num++;
			int t=0;
			for(int k=0;k<m-c;k++)t^=(((p[i]>>a[k])&1)<<k);
			for(int j=0;j<num;j++){
				for(int s=0;s<=S;s++){
					int v=dp[j][s];
					if(!v)continue;
					add(buf[j][s],v);
					add(buf[j+1][s^t],v);
				}
			}
			for(int j=0;j<=num;j++)for(int s=0;s<=S;s++)dp[j][s]=buf[j][s],buf[j][s]=0;
		}
		for(int i=0;i<=num;i++)
			for(int s=0;s<=S;s++)
				add(f[i+__builtin_popcount(s)],dp[i][s]);
	}
	for(int i=0;i<=m;i++)printf("%d ",f[i]);
	puts("");
    return 0;
}
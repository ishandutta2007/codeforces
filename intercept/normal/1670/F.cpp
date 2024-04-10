#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=2009;
ll n,l,r,z;
int vis[109][2009];
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int dfs(int st,ll m,ll x){
	int k=min(n*2,m);
	if(vis[st][k]!=-1)return vis[st][k];
	int o=z>>st&1,ans=0;
	
	for(int i=o;i<=min(n,m);i+=2){
		if(st==0)ans=(ans+c(n,i))%mod;
		else ans=(1ll*c(n,i)*dfs(st-1,(m-i)*2ll+(x>>(st-1)&1),x)%mod+ans)%mod;
	}
	return vis[st][k]=ans;
}
int main(){
	pre();
	cin>>n>>l>>r>>z;
	ll s=0;
	memset(vis,-1,sizeof(vis));
	s=dfs(62,r/(1ll<<62),r);
	memset(vis,-1,sizeof(vis));
	s=(s+mod-dfs(62,(l-1)/(1ll<<62),l-1))%mod;
	cout<<s<<endl;
	return 0;
}
/*
2 1 7 1
*/
// Hydro submission #61bc80f16bddd07850c211df@1639743729725
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,mod=1e9+7;
int a[N],b[N],n,rk[N],p[N],c[2][N];
void add(int p,int x,int y){for(;x<=n;x+=x&-x)c[p][x]=(c[p][x]+y)%mod;}
int ask(int p,int x){int ans=0;for(;x;x-=x&-x)ans=(ans+c[p][x])%mod;return ans;}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)rk[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int i=1;i<=n;i++)p[i]=1ll*i*(n-i+1)%mod;
	for(int i=1;i<=n;i++){
		p[i]=(p[i]+1ll*ask(0,rk[i])*(n-i+1)%mod)%mod;
		add(1,rk[i],1);
		add(0,rk[i],i);
	}	
	memset(c,0,sizeof(c));
	for(int i=n;i;i--){
		p[i]=(p[i]+1ll*((1ll*ask(1,rk[i]-1)*(n+1)%mod-ask(0,rk[i]-1))%mod+mod)%mod*i%mod)%mod;
		add(1,rk[i],1);
		add(0,rk[i],i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+1ll*p[i]*a[i]%mod)%mod;
	cout<<ans;
}
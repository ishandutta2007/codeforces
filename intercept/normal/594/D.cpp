#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
const int M=1e6+9;
int n,q;
int vis[M],p[M],a[M],ans[M],s[M],inv[M];
vector<int>v[M];
vector<pii>g[M];
int bit[M];
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
void add(int x,int v){
	for(;x;x-=x&-x)bit[x]=1ll*bit[x]*v%mod;
}
int ask(int x,int rex=1){
	for(;x<=n;x+=x&-x)rex=1ll*rex*bit[x]%mod;
	return rex;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	s[0]=1;
	for(int i=1;i<=n;++i)cin>>a[i],bit[i]=1,s[i]=1ll*s[i-1]*a[i]%mod;
	inv[1]=1;
	for(int i=2;i<M;++i){
		inv[i]=kpow(i,mod-2);
		if(!vis[i])v[i].eb(i);
		for(int j=i+i;j<M;j+=i){
			vis[j]=1;
			if(!vis[i])v[j].eb(i);
		}
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int l,r;
		cin>>l>>r;
		g[r].eb(l,i);
	}
	for(int i=1;i<=n;++i){
		for(auto o:v[a[i]]){
			add(i,1ll*(o-1)*inv[o]%mod);
			if(p[o])add(p[o],1ll*inv[o-1]*o%mod);
			p[o]=i;
		}
		for(auto o:g[i]){
			ans[o.se]=1ll*s[i]*kpow(s[o.fi-1],mod-2)%mod*ask(o.fi)%mod;
		}
	}
	for(int i=1;i<=q;++i)cout<<ans[i]<<"\n";
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
1
5 6

*/
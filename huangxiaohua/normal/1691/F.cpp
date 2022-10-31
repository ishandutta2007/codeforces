#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,sz[200500];
ll jc[1005000],inv[1005000],res,f[1005000],g;
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
vector<int> v[200500];

void dfs(int x,int fa,ll h=0){
	vector<ll> v2;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		sz[x]+=sz[i];
		h=su(h,M-c(sz[i],m));
	}
	sz[x]++;
	h=su(h,c(sz[x],m));
	f[x]=h*su(M,sz[x]-n)%M;
	g=su(g,f[x]);
}

void dfs2(int x,int fa,ll f1){
	ll f2,h2,tmp=c(n-sz[x],m);
	res+=f1+g-f[x]+M;res%=M;
	for(auto i:v[x]){
		if(i==fa)continue;
		tmp=su(tmp,c(sz[i],m));
	}
	for(auto i:v[x]){
		if(i==fa)continue;
		h2=-tmp+c(sz[i],m)+c(n-sz[i],m);
		h2=(h2%M+M)%M;
		f2=su(f1,M-f[x]);
		f2=su(f2,h2*su(M,-sz[i])%M );
		dfs2(i,x,f2);
	}
}

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=397802501;
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	res=1ll*n*c(n,m)%M*n%M;
	dfs(1,0);
	dfs2(1,0,0);
	cout<<res;
}
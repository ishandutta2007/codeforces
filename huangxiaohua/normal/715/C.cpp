#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,siz[100500],tot,vis[100500],rt,w;
ll x,y,M,inv[100500],pw[100500];
vector<pair<int,int> >v[100500];
void exgcd(ll a, ll b,ll& x,ll& y) {
	if(b==0){x=1;y=0;return;}
	exgcd(b, a % b, y, x);
	y-=a/b*x;
}
void dfs0(int x,int fa){
	tot++;siz[x]=1;
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		dfs0(i,x);siz[x]+=siz[i];
	}
}
void dfs1(int x,int fa){
	if(rt)return;
	if(siz[x]*2>=tot){
		for(auto [i,j]:v[x]){
			if(i==fa||vis[i])continue;
			if(siz[i]*2>tot)goto aaa;
		}
		rt=x;return;
	}
	aaa:;
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		dfs1(i,x);
	}
}
map<ll,ll> mp;
ll it,cur,res;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
void dfs2(int x,int fa){
	res+=mp[cur];
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		cur=su(cur,pw[it]*j%M);it++;
		dfs2(i,x);
		it--;cur=su(cur,M-pw[it]*j%M)%M;
	}
}
void dfs3(int x,int fa){
	mp[ (M-cur)%M*inv[it]%M ]++;
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		ll lst=cur;
		cur=(cur*10+j)%M;it++;
		dfs3(i,x);
		cur=lst;it--;
	}
}
void dfs4(int x,int fa){
	mp[ (M-cur)%M*inv[it]%M ]--;
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		ll lst=cur;
		cur=(cur*10+j)%M;it++;
		dfs4(i,x);
		cur=lst;it--;
	}
}
void solve(int t){
	vis[t]=1;
	mp.clear();mp[0]=1;
	for(auto [i,j]:v[t]){
		if(vis[i])continue;
		it=1;cur=j%M;
		dfs3(i,0);
	}
	res+=mp[0];res--;
	for(auto [i,j]:v[t]){
		if(vis[i])continue;
		it=1;cur=j%M;dfs4(i,0);
		it=1;cur=j%M;dfs2(i,0);
		it=1;cur=j%M;dfs3(i,0);
	}
	for(auto [i,j]:v[t]){
		if(vis[i])continue;
		rt=0;tot=0;
		dfs0(i,0);dfs1(i,0);
		solve(rt);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin>>n>>M;
	if(M==1){
		cout<<1ll*n*(n-1);return 0;
	}
	exgcd(10,M,x,y);
	x=(x%M+M)%M;
	inv[0]=1;inv[1]=x;
	for(i=2;i<=100000;i++)inv[i]=inv[i-1]*inv[1]%M;
	pw[0]=1;
	for(i=1;i<=100000;i++)pw[i]=pw[i-1]*10%M;
	for(i=1;i<n;i++){
		cin>>j>>k>>w;j++;k++;
		v[j].push_back({k,w});
		v[k].push_back({j,w});
	}
	dfs0(1,0);dfs1(1,0);
	solve(rt);
	cout<<res;
}
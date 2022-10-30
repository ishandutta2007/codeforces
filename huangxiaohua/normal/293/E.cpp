#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l1,l2,su,dep[100500],dep2[100500],rt,siz[100500],vis[100500],de,sz,it;
int f[100500];
ll res,ans;
vector<pair<int,int> > v[100500];

struct sb{
	int x,y;
	bool operator<(const sb a)const{return x<a.x;}
}s[100500];

void add(int x,int y){
	for(int i=x;i<=100005;i+=(-i&i)){
		f[i]+=y;
	}
}

int get(int x,int z=0){
	if(x<=0)return 0;
	for(int i=x;i;i-=(-i&i)){
		z+=f[i];
	}return z;
}

void dfs0(int x,int fa){
	siz[x]=1;
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		dfs0(i,x);siz[x]+=siz[i];
	}
}

void dfs1(int x,int fa){
	int y=1;
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		dfs1(i,x);
		if(siz[i]>(sz/2+1))y=0;
	}
	if(sz-siz[x]>(sz/2+1))y=0;
	if(y)rt=x;
}

void dfs2(int x,int fa){
	dep[x]=dep[fa]+1;
	for(auto [i,j]:v[x]){
		if(vis[i]||i==fa)continue;
		dep2[i]=dep2[x]+j;
		dfs2(i,x);
		siz[x]+=siz[i];
	}
}

void dfs3(int x,int fa){
	s[++it].x=dep2[x];
	s[it].y=dep[x];
	for(auto [i,j]:v[x]){
		if(vis[i]||i==fa)continue;
		dfs3(i,x);
	}
}

ll solve1(int x){
	it=0;ans=0;
	dfs3(x,0);
	int l=1,r=it,mx=0;
	sort(s+1,s+it+1);
	for(int i=1;i<=it;i++){
		mx=max(mx,s[i].y);
		add(s[i].y,1);
	}
	while(l<=r){
		if(s[l].x+s[r].x<=l2){
			add(s[l].y,-1);
			ans+=get(l1-s[l].y+2);
			l++;
		}
		else{
			add(s[r].y,-1);r--;
		}
	}
	memset(f,0,mx*4+50);
	return ans;
}

void solve(int rt){
	dep2[rt]=0;dfs2(rt,0);
	res+=solve1(rt);
	vis[rt]=1;
	for(auto [i,j]:v[rt]){
		if(vis[i])continue;
		res-=solve1(i);
	}
}

void dfz(int x){
	if(vis[x])return;
	rt=x;
	dfs0(x,0);
	sz=siz[x];
	dfs1(x,0);
	solve(rt);
	for(auto [i,j]:v[rt]){
		if(!vis[i])dfz(i);
	}
}

int main(){
	scanf("%d%d%d",&n,&l1,&l2);
	for(i=2;i<=n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back({i,k});
		v[i].push_back({j,k});
	}
	dfz(1);
	printf("%lld",res);
}
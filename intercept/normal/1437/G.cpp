#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=6e5+9;
int n,q;
int sz,id;
int L[M],R[M],c[M][26];
char s[M];
int f[M],vis[M];
vector<int>g[M],po[M];
string t[M];
vector<pii>p[M];
void get(){
	queue<int>q;
	for(int i=0;i<26;++i){
		if(c[0][i])q.push(c[0][i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int o=0;o<26;++o){
			int v=c[u][o];
			if(!v)c[u][o]=c[f[u]][o];
			else f[v]=c[f[u]][o],vis[v]|=vis[f[v]],q.push(v);
		}
	}
}
int rt[M],ma[M*40],ls[M*40],rs[M*40];
void update(int &now,int las,int l,int r,int x,int y,int v){
	now=++id;
	ma[now]=ma[las];
	ls[now]=ls[las];
	rs[now]=rs[las];
	if(x<=l&&r<=y){
		ma[now]=max(ma[now],v);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)update(ls[now],ls[las],l,mid,x,y,v);
	if(y>mid)update(rs[now],rs[las],mid+1,r,x,y,v);
}
int query(int now,int l,int r,int x){
	if(l==r)return ma[now];
	int mid=(l+r)>>1;
	return max(x<=mid?query(ls[now],l,mid,x):query(rs[now],mid+1,r,x),ma[now]);
}
void dfs(int u,int fa){
	if(fa>=0){
		rt[u]=rt[fa];
		for(auto w:po[u]){
			for(int i=0;i<p[w].size();++i){
				int r;
				if(i==p[w].size()-1)r=q;
				else r=p[w][i+1].fi-1;
				update(rt[u],rt[u],1,q,p[w][i].fi,r,p[w][i].se);
			}
		}
		
	}
	for(auto v:g[u]){
		dfs(v,u);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>(s+1);
		int m=strlen(s+1);
		for(int j=1,u=0;j<=m;++j){
			int o=s[j]-'a';
			if(!c[u][o])c[u][o]=++sz;
			u=c[u][o];
			if(j==m)po[u].eb(i),vis[u]=1;
		}
	}
	get();
	for(int i=1;i<=sz;++i){
		g[f[i]].eb(i);
	}
	for(int i=1;i<=q;++i){
		int o;
		cin>>o;
		if(o==1){
			int x,y;
			cin>>x>>y;
			p[x].eb(i,y);
		}
		else {
			cin>>t[i];
		}
	}
	dfs(0,-1);
	for(int i=1;i<=q;++i){
		if(t[i].size()){
			bool flag=0;
			int ans=0;
			for(int j=0,u=0;j<t[i].size();++j){
				int o=t[i][j]-'a';
				u=c[u][o];
				flag|=vis[u];
				ans=max(ans,query(rt[u],1,q,i));
			}
			if(!flag)cout<<"-1\n";
			else cout<<ans<<"\n";
		}
	}
	return 0;
}
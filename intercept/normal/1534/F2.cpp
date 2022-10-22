#include<bits/stdc++.h>
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int M=4e5+9;
int n,m,sz,tot;
int a[M];
int f[M],siz[M],dfn[M],in[M],low[M],L[M],R[M],fs[M];
string s[M];
vector<int>g[M],h[M],fg[M];
int st[M];
int id(int x,int y){
	return (x-1)*m+y;
}
void add(int x,int y){g[x].eb(y);}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int u){
	dfn[u]=low[u]=++sz;
	st[++tot]=u;
	in[u]=1;
	for(auto v:g[u]){
		if(!dfn[v])dfs(v);
		if(in[v])low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u]){
		int v=0;
		while(u!=v){
			v=st[tot--];
			in[v]=0;
			f[find(v)]=find(u);
		}
	}
}
int num=0,cnt=0;
pair<int,int>p[M];
int vis[M],b[M];
int dp[M];
bool vis1[M],vis2[M],vis3[M];
void GET(int u){
	vis1[u]=1;
	for(auto v:fg[u]){
		if(!vis1[v])GET(v);
		dp[u]=max(dp[u],dp[v]);
	}
	if(L[u]){
		dp[u]++;
		if(dp[u]>=2)vis[u]=-1;
	}
}
void get(int u){
	vis2[u]=1;
	if(L[u]){
		if(!vis[u]){
			vis[u]=(u-1)%m+1,b[++num]=(u-1)%m+1;
		}
	}
	for(auto v:h[u])if(!vis2[v])get(v);
}
void dg(int u){
	vis3[u]=1;
	for(auto v:h[u]){
		if(!vis3[v])dg(v);
		L[u]=min(L[u],L[v]);
		R[u]=max(R[u],R[v]);
	}
	p[++cnt]=mp(L[u],R[u]);
}
int main(){
	cin>>n>>m;
	s[0].resize(m+2);
	s[n+1].resize(m+2);
	for(int i=1;i<=n*m;++i)f[i]=i;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		s[i]=" "+s[i]+" ";
	}
	for(int i=1;i<=m;++i){
		cin>>a[i];
		if(!a[i])a[i]=-1;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){ 
			if(s[i][j]=='#'){
				int k=i;
				if(s[k-1][j]=='#')add(id(i,j),id(k-1,j));
				while((s[k][j]!='#'||k==i)&&k<=n){
					if(s[k][j+1]=='#')add(id(i,j),id(k,j+1));
					if(s[k][j-1]=='#')add(id(i,j),id(k,j-1));
					if(s[k+1][j]=='#')add(id(i,j),id(k+1,j));
					k++;
				}
			}
		}
	}
	for(int i=n;i>=1;--i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='#'){
				a[j]--;
				if(!a[j])L[id(i,j)]=1;
			}
		}
	}
	for(int i=1;i<=n*m;++i){
		if(!dfn[i])dfs(i);
	}

	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			int u=id(i,j);
			L[find(u)]|=L[u];
			for(auto v:g[u]){
				if(find(u)!=find(v)){
					siz[find(v)]++;
					fs[find(u)]++;
					h[find(u)].push_back(find(v));
					fg[find(v)].push_back(find(u));
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int u=id(i,j);
			if(s[i][j]=='#'&&fs[u]==0&&u==find(u)&&!vis1[u]){
				GET(u);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int u=id(i,j);
			if(s[i][j]=='#'&&siz[u]==0&&u==find(u)&&!vis2[u]){
				get(u);
			}
		}
	}
	sort(b+1,b+num+1);
	for(int i=1;i<=n*m;++i){
		L[i]=1e9;
		R[i]=0;
		if(vis[i]>0)L[i]=R[i]=lower_bound(b+1,b+num+1,vis[i])-b;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int u=id(i,j);
			if(s[i][j]=='#'&&siz[u]==0&&u==find(u)&&!vis3[u]){
				dg(u);
			}
		}
	}
	p[++cnt]=mp(num+1,num+1);
	sort(p+1,p+cnt+1);
	for(int i=1,l=1,r=0;i<=cnt;++i){
		if(p[i].fi<=l)r=max(r,p[i].se+1);
		else if(p[i].fi<=p[i].se){	
			l=r;
			ans++;
			r=max(r,p[i].se+1);
			if(l==num+1)break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
3 5
#.#.#
...#.
..#..
1 0 2 0 1
*/
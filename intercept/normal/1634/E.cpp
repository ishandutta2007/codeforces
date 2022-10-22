#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,num,o,tot=1;
vector<int>a[M],p;
map<int,int>mp;
int cur[M],head[M],vis[M<<1];
struct E{
	int ne,v,j,k,x;
}e[M<<1];
void add(int x,int y,int u,int v,int w){
	if(!mp.count(x))mp[x]=++num;
	if(!mp.count(y))mp[y]=++num;
	x=mp[x];
	y=mp[y];
	e[++tot]=E{head[x],y,u,v,w};head[x]=tot;
	e[++tot]=E{head[y],x,v,u,w};head[y]=tot;
}
void dfs(int u){
	for(int &i=head[u];i;i=e[i].ne){
		if(vis[i])continue;
		vis[i]=vis[i^1]=1;
		int v=e[i].v,j=e[i].j,k=e[i].k,x=e[i].x;
		dfs(v);
		a[x][j]=o;
		a[x][k]=o^1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,k;i<=n;++i){
		scanf("%d",&k);
		for(int j=0,x;j<k;++j){
			scanf("%d",&x);
			a[i].emplace_back(x);
			p.emplace_back(x);
			if(j&1){
				add(a[i][j-1],a[i][j],j-1,j,i);
			}
		}
	}
	sort(p.begin(),p.end());
	for(int i=0,S=p.size();i<S;i+=2){
		if(p[i]!=p[i+1]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=num;++i)dfs(i);
	for(int i=1;i<=n;++i){
		for(auto v:a[i])putchar(v?'L':'R');
		puts("");
	}
	return 0;
}
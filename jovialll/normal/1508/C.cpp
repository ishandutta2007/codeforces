#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define M 705
#define pb push_back 
long long ans;
int n,m,x[N],w[N],y[N],f[N],p[M][M];
vector<int>son[N],V[N];
struct edge{
	int x,y,v;
}e[N];
inline bool cmp(edge aa,edge bb){return aa.v<bb.v;}
int find(int x){if(x!=f[x])f[x]=find(f[x]);return f[x];}
int check(){
	int i,j,f1,f2;
	for(i=1;i<=m;++i)p[x[i]][y[i]]=p[y[i]][x[i]]=1;
	for(i=1;i<=n;++i)f[i]=i;
	for(i=2;i<=n;++i)for(j=1;j<i;++j){
		if(!p[i][j]){
			f1=find(i);f2=find(j);
			if(f1==f2)return 1;f[f1]=f2;
		}
	}
	return 0;
}
struct gg1{
	int cl,las,ed,tot,T,vst[N],l[N],in[N];
	queue<int>q;
	void bfs(int fm){
		las=0;int tmp,i,x,j,ee;
		for(i=0;i<son[fm].size();++i){
			in[son[fm][i]]=1;
			l[son[fm][i]]=las;
			for(j=las+1;j<son[fm][i];++j){
				q.push(j);
			}
			las=son[fm][i];
		}ed=las;
		for(j=las+1;j<=n;++j)q.push(j);
		while(q.size()){
			x=q.front();q.pop();
			vst[x]=cl;
			las=ed;ed=0;ee=0;
			for(i=son[x].size()-1;~i;--i){
				T=son[x][i];
				if(!in[T])continue;
				while(las!=T){
					q.push(las);in[las]=0;
					tmp=l[las];l[las]=0;las=tmp;
				}
				las=l[las];
				if(ee)l[ee]=T,ee=T;
				else ed=ee=T;
			}
			while(las){
				q.push(las);
				in[las]=0;tmp=l[las];l[las]=0;las=tmp;
			}
			l[ee]=0; 
		}
		for(i=0;i<son[fm].size();++i)
			in[son[fm][i]]=l[son[fm][i]]=0;			
	}
	void solve(){
		int i;
		for(i=1;i<=m;++i)son[x[i]].push_back(y[i]),son[y[i]].push_back(x[i]);
		for(i=1;i<=n;++i)sort(son[i].begin(),son[i].end());
		for(i=1;i<=n;++i){
			if(!vst[i]){
				++cl;
				bfs(i);
			}
		}
		for(i=1;i<=m;++i){
			if(vst[x[i]]!=vst[y[i]]){
				e[++tot].x=vst[x[i]];
				e[tot].y=vst[y[i]];
			}
			e[tot].v=w[i];
		}
		sort(e+1,e+tot+1,cmp);
		for(i=1;i<=cl;++i)f[i]=i;
		for(i=1;i<=tot;++i){
			if(find(e[i].x)!=find(e[i].y)){
				f[find(e[i].x)]=find(e[i].y);
				ans+=e[i].v;
			}
		} 
		cout<<ans;return ;
	}
}f1;
struct gg2{
	int fa[N][20],can[N][20],dep[N];
	void dfs(int now,int fat){
		fa[now][0]=fat;dep[now]=dep[fat]+1;int i,T;
		for(i=1;i<18;++i)fa[now][i]=fa[fa[now][i-1]][i-1],can[now][i]=can[fa[now][i-1]][i-1]|can[now][i-1];
		for(i=0;i<son[now].size();++i){
			if((T=son[now][i])!=fat){
				can[T][0]=(V[now][i]==0),dfs(T,now);
			} 
		}
	}
	int lca(int x,int y){
		if(dep[x]>dep[y])swap(x,y);int i,rr=0;
		for(i=17;~i;--i)if(dep[fa[y][i]]>=dep[x])rr|=can[y][i],y=fa[y][i];
		if(x==y)return rr;
		for(i=17;~i;--i){
			if(fa[x][i]!=fa[y][i])rr=rr|can[x][i]|can[y][i],x=fa[x][i],y=fa[y][i];
		}
		return rr|can[x][0]|can[y][0];
	}
	void solve(){
		int i,val=0,tot=0,j;long long res=0;
		for(i=1;i<=m;++i)p[x[i]][y[i]]=p[y[i]][x[i]]=w[i],val^=w[i];
		for(i=1;i<=n;++i)for(j=1;j<i;++j)e[++tot].x=i,e[tot].y=j,e[tot].v=p[i][j];
		sort(e+1,e+tot+1,cmp);dfs(1,0); 
		for(i=1;i<=n;++i)f[i]=i;
		for(i=1;i<=tot;++i){
			if(find(e[i].x)!=find(e[i].y)){
				f[find(e[i].x)]=find(e[i].y);
				son[e[i].x].pb(e[i].y);
				son[e[i].y].pb(e[i].x);
				V[e[i].x].pb(e[i].v);
				V[e[i].y].pb(e[i].v);
				ans+=e[i].v;
			}
		}
		dfs(1,0);
		res=ans+val;
		for(i=1;i<=m;++i){
			if(lca(x[i],y[i])){
				res=min(ans+w[i],res);
			}
		}
		cout<<res;
	}
}f2;
int i;
int main(){
//	freopen("a.txt","r",stdin);
//	freopen("a.out","w",stdout);
 	cin>>n>>m;
	for(i=1;i<=m;++i)cin>>x[i]>>y[i]>>w[i];
	if(n>700||check()){
		f1.solve();
	}
	else {
		f2.solve();
	}
}
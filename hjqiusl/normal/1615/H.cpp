#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
const int inf=1e18;
template<class F>
class Maxflow{
	const F inf=numeric_limits<F>::max();
	struct Edge{
		int u,v;
		F w;
	};
	int n,S,T;
	vector<Edge> edge;
	vector<vector<int> > G;
	vector<int> dep;
	vector<int> iter;
	bool bfs(){
		fill(dep.begin(),dep.end(),-1);
		queue<int> q;
		q.push(S);
		dep[S]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto id:G[u]){
				int v=edge[id].v;
				if(edge[id].w>0&&dep[v]==-1){
					dep[v]=dep[u]+1;
					q.push(v);
					if(v==T)return true;
				}
			}
		}
		return false;
	}
	F dfs(int u,F limit){
		if(u==T||!limit)return limit;
		F flow=0;
		for(int &i=iter[u];i<(int)G[u].size();++i){
			int id=G[u][i];
			int v=edge[id].v;
			F w=edge[id].w;
			if(dep[v]==dep[u]+1){
				F tmp=dfs(v,min(limit,w));
				if(tmp>0){
					edge[id].w-=tmp,edge[id^1].w+=tmp;
					flow+=tmp,limit-=tmp;
					if(limit==0)break;	
				}
			}
		}
		if(flow==0)dep[u]=-1;
		return flow;
	}
public:
	vector<bool> vis;
	Maxflow(int _n):n(_n){
		dep.resize(n+1),iter.resize(n+1),G.resize(n+1);
		vis.resize(n+1);
	}
	void adde(int u,int v,F w){
		G[u].push_back(edge.size()),edge.push_back({u,v,w});
		G[v].push_back(edge.size()),edge.push_back({v,u,0});	
	}
	F Dinic(int _S,int _T){
		S=_S,T=_T;
		F ans=0;
		while(bfs()){
			fill(iter.begin(),iter.end(),0);
			ans+=dfs(S,inf);
		}
		return ans;
	}
	void Get(int u){
		vis[u]=true;
		for(auto id:G[u]){
			int v=edge[id].v;
			if(edge[id].w>0&&!vis[v]){
				Get(v);
			}
		}
	}
};
#define N 2333
ull c[N];
int n,m,p[N],a[N],b[N],g[N];
int Val[N];
vector<int> H[N];
template<class T,int B>
class Basis{
	T d[B];
public:
	Basis(){fill(d,d+B,0);}
	int Insert(T x){
		for(int i=B-1;i>=0;--i){
			if(x>>i&1){
				if(!d[i]){
					d[i]=x;
					return i;
				}
				else x^=d[i];
			}
		}
		return -1;
	}
	void reset(int x){d[x]=0;}
};
ll sqr(int x){
	return 1LL*x*x;
}
void Solve(vector<int> &V,int L,int R){
	if(V.empty())return;
	if (L==R)
	{
		for (auto u:V) g[u]=Val[L];
		return;
	}
	int S=V.size(),T=V.size()+1;
	Maxflow<int> G(V.size()+1);
	static int id[N];
	if(~id[0])memset(id,-1,sizeof(id));
	for(int i=0;i<(int)V.size();++i){
		id[V[i]]=i;
	}
	for(auto u:V){
		for(auto v:H[u]){
			if(~id[v]){
				G.adde(id[u],id[v],inf);
			}
		}	
	}
	// if(L+1==R){
		// int mid=(L+R)>>1;
		// for(int i=0;i<(int)V.size();++i){
			// int u=V[i];
			// if(mid<p[u])G.adde(S,i,p[u]-mid);
			// else G.adde(i,T,mid-p[u]);
		// }
		// G.Dinic(S,T);
		// G.Get(S);
		// for(auto u:V){
			// g[u]=G.vis[id[u]]?R:L;	
		// }
		// for(auto x:V)id[x]=-1;
		// return;
	// }
	int mid=(L+R)>>1;
	for(int i=0;i<(int)V.size();++i){
		int u=V[i];
		ll c=abs(p[u]-Val[mid])-abs(p[u]-Val[mid+1]);
		// cout<<"??"<<c<<' "<<a[u]<<endl;
		if(c>0)G.adde(S,i,c);
		else G.adde(i,T,-c);
	}
	G.Dinic(S,T);
	G.Get(S);
	vector<int> A,B;
	for(auto u:V){
		if(G.vis[id[u]]){
			B.push_back(u);	
		}
		else{
			A.push_back(u);
		}
	}
	for(auto x:V)id[x]=-1;
	Solve(A,L,mid),Solve(B,mid+1,R);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>p[i],Val[i]=p[i];
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		H[x].push_back(y);
	}
	vector<int> all;
	for(int i=1;i<=n;++i)all.push_back(i);
	sort(Val+1,Val+n+1);
	int pp=unique(Val+1,Val+n+1)-Val-1;
	// cout<<"???"<<pp<<endl;
	// for (int i=1;i<=pp;i++) cout<<Val[i]<<" ";
	// cout<<endl;
	Solve(all,1,pp);
	ll ans=0;
	for(int i=1;i<=n;++i){
		cout<<g[i]<<" ";
		ans+=abs(g[i]-p[i]);
	}
	// cout<<ans<<'\n';
	return 0;
}
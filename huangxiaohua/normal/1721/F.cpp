#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 2000000
struct Dinic{
	int Q[N],d[N],L,R;
	int tot,cur[N],Head[N],Next[N];
	struct edge{int to,cap,flow,id;}W[N];
	void Init(){memset(Head,(tot=0)-1,sizeof(Head));}
	void Add(int x,int y,int cap,int id){
		Next[tot]=Head[x];
		W[Head[x]=tot++]={y,cap,0,id};
		Next[tot]=Head[y];
		W[Head[y]=tot++]={x,0,0,id};
	}
	int BFS(int s,int t){
		memset(d,0,sizeof(d));
		d[Q[L=R=1]=s]=1;
		while(L<=R){
			int x=Q[L++];
			cur[x]=Head[x];
			for(int i=Head[x];~i;i=Next[i]){
				edge e=W[i];
				if(!d[e.to]&&e.flow<e.cap)
					d[Q[++R]=e.to]=d[x]+1;
			}
		}
		return d[t];
	}
	int DFS(int x,int t,int flow){
		if(x==t||!flow)return flow;
		int pre=flow,f;
		for(int &i=cur[x];~i;i=Next[i]){
			edge e=W[i];
			if(d[e.to]==d[x]+1&&(f=DFS(e.to,t,min(e.cap-e.flow,flow)))){
				W[i].flow+=f;W[i^1].flow-=f;
				if(!(flow-=f))return pre;
			}
		}
		return pre-flow;
	}
	ll Solve(int s,int t){
		ll res=0;
		while(BFS(s,t))res+=DFS(s,t,INT_MAX);
		return res;
	}
}di;

int i,j,k,n,m,t,n1,n2,nmsl;
int sb[N],f[N],h[N],vis[N];
ll res;
vector<pair<int,int> > del;
vector<int> bian;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	di.Init();
	cin>>n1>>n2>>m>>t;
	for(i=1;i<=n1;i++)di.Add(0,i,1,-1);
	for(i=1;i<=n2;i++)di.Add(n1+i,n1+n2+1,1,-1);
	for(i=1;i<=m;i++){
		cin>>j>>k;
		di.Add(j,k+n1,1,i);
	}
	nmsl=di.Solve(0,n1+n2+1);
	for(i=1;i<=n1;i++){
		k=0;
		for(j=di.Head[i];~j;j=di.Next[j]){
			auto &[to,cap,flow,id]=di.W[j];
			if(to==0||to==n1+n2+1)continue;
			if(flow==1){
				res+=id;
				sb[i]=sb[to]=id;
				f[i]=to;f[to]=i;
				bian.push_back(id);
			}
		}
	}
	queue<int> q;
	for(i=1;i<=n1+n2;i++){
		if(!sb[i])q.push(i),vis[i]=1;
	}
	while(!q.empty()){
		k=q.front();q.pop();
		for(j=di.Head[k];~j;j=di.Next[j]){
			auto &[to,cap,flow,id]=di.W[j];
			if(to==0||to==n1+n2+1||!sb[to])continue;
			if(!vis[f[to]]){
				vis[f[to]]=1;
				q.push(f[to]);
			}
		}
	}
	for(i=1;i<=n1+n2;i++){
		if(!vis[i])del.push_back({(i>n1)?n1-i:i,sb[i]}),vis[i]=vis[f[i]]=1;
	}
	while(t--){
		int ty;
		cin>>ty;
		if(ty==1){
			auto [id,w]=del.back();
			del.pop_back();
			res-=w;
			h[w]=1;
			cout<<1<<'\n'<<id<<'\n'<<res<<endl;
			nmsl--;
		}
		else{
			cout<<nmsl<<'\n';
			for(auto w:bian){
				if(!h[w]){
					cout<<w<<' ';
				}
			}
			cout<<endl;
		}
	}
}
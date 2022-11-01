#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll ans=1;
#define fi first
#define se second
int n;
vector<int>adj[500001];
int anc[19][500001];
int d[500001];
void dfs(int id,int p){
	for(auto cur:adj[id]){
		if(cur==p) continue;
		anc[0][cur]=id;
		for(int i=1; i<=18 ;i++){
			anc[i][cur]=anc[i-1][anc[i-1][cur]];
		}
		d[cur]=d[id]+1;
		dfs(cur,id);
	}
}
int kth_anc(int id,int k){
	for(int i=18; i>=0 ;i--){
		if(k&(1<<i)) id=anc[i][id];
	}
	return id;
}
int lca(int u,int v){
	if(d[u]>d[v]) swap(u,v);
	v=kth_anc(v,d[v]-d[u]);
	if(u==v) return u;
	for(int i=18; i>=0 ;i--){
		if(anc[i][u]!=anc[i][v]){
			u=anc[i][u];v=anc[i][v];
		}
	}
	return anc[0][u];
}
int a[500001];
vector<pair<int,int> >cute[500001];
ll pap[500001],pbp[500001];
void dfs2(int id,int p){
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs2(cur,id);
		pbp[id]+=pbp[cur];
		pap[id]+=pap[cur];
	}
	if(pbp[id]) cute[anc[0][id]].push_back({id,anc[1][id]});
	if(pap[id]) cute[anc[0][id]].push_back({anc[1][id],id});
}
int nxt[1000002];
int prv[1000002];
bool vis[1000002];
ll f[1000002];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	f[0]=1;
	for(int i=1; i<=n ;i++) f[i]=f[i-1]*i%mod;
	for(int i=2; i<=n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==0) continue;
		if(a[i]==i) return cout << "0\n",0;
		int s=a[i],t=i;
		int x=lca(s,t);
		int sb=-1;
		int tb=-1;
		if(x!=s){
			sb=kth_anc(s,d[s]-d[x]-1);
			int b=sb;
			pbp[s]++;
			pbp[b]--;
		}
		if(x!=t){
			tb=kth_anc(t,d[t]-d[x]-1);
			int b=tb;
			pap[t]++;
			pap[b]--;
		}
		if(x!=s) cute[s].push_back({n+2,anc[0][s]});
		else cute[s].push_back({n+2,tb});
		if(x!=t) cute[t].push_back({anc[0][t],n+1});
		else cute[t].push_back({sb,n+1});
		if(x!=s && x!=t){
			cute[x].push_back({sb,tb});
		}
	}
	dfs2(1,0);
	for(int i=1; i<=n ;i++){
		adj[i].push_back(n+2);
		adj[i].push_back(n+1);
		for(auto cur:adj[i]) nxt[cur]=vis[cur]=prv[cur]=0;
		for(auto cur:cute[i]){
			if(nxt[cur.fi]!=0 && nxt[cur.fi]!=cur.se) return cout << "0\n",0;
			if(prv[cur.se]!=0 && prv[cur.se]!=cur.fi) return cout << "0\n",0;
			nxt[cur.fi]=cur.se;prv[cur.se]=cur.fi;
		}
		int cnt=0;
		bool fuck=false;
		for(auto cur:adj[i]){
			if(vis[cur]) continue;
			if(prv[cur]!=0) continue;
			int x=cur;
			vis[x]=true;
			while(nxt[x]!=0){
				x=nxt[x];
				vis[x]=true;
			}
			if(cur==n+2 && x==n+1) fuck=true;
			cnt++;
		}
		if(fuck && cnt!=1) return cout << "0\n",0;
		for(auto cur:adj[i]){
			if(!vis[cur]) return cout << "0\n",0;
		}
		ans=ans*f[cnt-2+(cnt==1)]%mod;
	}
	cout << ans << endl;
}
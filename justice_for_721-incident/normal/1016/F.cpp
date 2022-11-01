#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
int n,q;
ll d[300001];
vector<pair<ll,int> >adj[300001];
bool vis[300001];
bool ib[300001];
int prv[300001];
int b[300001];
int pb[300001];
int size[300001];
ll maxi[300001];
void dfs(int id){
	vis[id]=true;
	for(auto cur:adj[id]){
		if(!vis[cur.se]){
			d[cur.se]=d[id]+cur.fi;
			prv[cur.se]=id;
			dfs(cur.se);
		}
	}
}
void dfs2(int id){
	size[pb[id]]++;
	maxi[pb[id]]=max(maxi[pb[id]],d[id]);
	for(auto cur:adj[id]){
		if(!pb[cur.se]){
			if(ib[cur.se]) pb[cur.se]=cur.se;
			else pb[cur.se]=pb[id];
			dfs2(cur.se);
		}
	}
}
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=2; i<=n ;i++){
		int u,v;
		ll w;
		cin >> u >> v >> w;
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	dfs(1);
	int cur=n;
	int cnt=0;
	while(cur!=0){
		ib[cur]=true;
		cnt++;
		cur=prv[cur];
	}
	cur=n;
	for(int i=cnt; i>=1 ;i--){
		b[i]=cur;
		cur=prv[cur];
	}
	pb[1]=1;
	dfs2(1);
	for(int i=1; i<=cnt ;i++){
		if(size[b[i]]>=3) ans=d[n];
		if(i!=1 && (size[b[i]]>=2 || size[b[i-1]]>=2)) ans=max(ans,maxi[b[i-1]]+maxi[b[i]]-d[b[i]]+d[n]-d[b[i]]);
		if(i>2) ans=max(ans,d[b[i-2]]+d[n]-d[b[i]]);
	}
	for(int i=1; i<=q ;i++){
		ll w;
		cin >> w;
		cout << min(d[n],ans+w) << endl;
	}
}
#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int n,val[500005],s[500005],depth[500005];
int store[1<<22],ans[500005];
int heavy[500005];
vi a[500005];

void dfs(int node){
	s[node]=1;
	int mx=0;
	for(auto i:a[node]){
		depth[i]=depth[node]+1;
		dfs(i);
		if(s[i]>mx){
			mx=s[i];
			heavy[node]=i;
		}
		s[node]+=s[i];
	}
}
void add(int node){
	store[val[node]]=max(store[val[node]],depth[node]);
	for(auto i:a[node]) add(i);
}
void rem(int node){
	store[val[node]]=-hell;
	for(auto i:a[node]) rem(i);
}
void query(int node,int u){
	ans[u]=max(ans[u],store[val[node]]+depth[node]-2*depth[u]);
	rep(i,0,22) ans[u]=max(ans[u],store[val[node]^(1<<i)]+depth[node]-2*depth[u]);
	for(auto i:a[node]) query(i,u);
}
void dfs2(int node,bool keep){
	for(auto i:a[node]){
		if(i!=heavy[node]){
			dfs2(i,0);
		}
	}
	if(heavy[node]) dfs2(heavy[node],1);
	store[val[node]]=max(store[val[node]],depth[node]);
	ans[node]=max(ans[node],store[val[node]]-depth[node]);
	rep(i,0,22) ans[node]=max(ans[node],store[val[node]^(1<<i)]-depth[node]);
	for(auto i:a[node]){
		if(i!=heavy[node]){
			query(i,node);
			add(i);
		}
	}
	if(!keep) rem(node);
}
void solve(){
	cin>>n;
	rep(i,2,n+1){
		int x;
		char ch;
		cin>>x>>ch;
		a[x].pb(i);
		val[i]=val[x]^(1<<(ch-'a'));
	}
	memset(store,-127,sizeof store);
	depth[1]=1;
	dfs(1);
	dfs2(1,0);
	for(int i=n;i>=1;i--){
		for(auto j:a[i]) ans[i]=max(ans[i],ans[j]);
	}
	rep(i,1,n+1) cout<<ans[i]<<" ";
	cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
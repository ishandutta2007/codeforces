#include<bits/stdc++.h>
using namespace std;
const int MAXN=2011;

int par[MAXN], sz[MAXN];

void init() {
	memset(par, -1, sizeof par);
	for(int i=0;i<MAXN;++i) {
		sz[i]=1;
	}
}

int get(int x) {
	if(par[x]==-1) return x;
	return par[x]=get(par[x]);
}

void merge(int x, int y) {
	int px=get(x), py=get(y);
	
	if(px==py) return ;
	
	if(sz[px]>sz[py]) {
		swap(px, py);
		swap(x, y); //:) lyft
	}
	
	par[px]=py;
	sz[py]+=sz[px];
}

set<int> adj[2001];
int b[2001];
int indeg[2001];
int atleast[2001];
int ans[2001];
bool ok=true;
set<pair<int,int>> st;
void dfs(int x, int par=-1, int ind=1) {
	b[x]=1;
	ans[x]=ind;
	for(auto i:adj[x]) {
		if(i==par) continue ;
		if(b[i]==1) ok=false;
		else {
			st.erase(st.lower_bound({indeg[i], i}));
			indeg[i]--;
			st.insert({indeg[i],i});
			//cerr<<indeg[i]<<" "<<i<<"\n";
			atleast[i]=max(atleast[i], ind+1);
		}
	}
	b[x]=2;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	int n,m;
	cin>>n>>m;
	string t[n];
	for(int i=0;i<n;++i) {
		cin>>t[i];
	}
	
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			if(t[i][j]=='=') {
				merge(i,j+n);
			}
		}
	}
	
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			if(t[i][j]=='>') {
				adj[get(j+n)].insert(get(i));
				//cerr<<get(j+n)<<" -> "<<get(i)<<"\n";
							if(get(i)==get(j+n)) ok=false;
			}else if(t[i][j]=='<') {
				adj[get(i)].insert(get(j+n));
				//cerr<<get(i)<<" -> "<<get(j+n)<<"\n";
							if(get(i)==get(j+n)) ok=false;
			}

		}
	}
	for(int i=0;i<n+m;++i) {
		for(auto j:adj[i]) indeg[j]++;
	}
	for(int i=0;i<n+m;++i) st.insert({indeg[get(i)], get(i)});
	while(ok && !st.empty()) {
		if(st.begin()->first!=0) {
			ok=false;
			break ;
		}else {
			int ind=st.begin()->second;
			//cerr<<ind<<"\n";
			st.erase(st.begin());
			dfs(ind, -1, max(atleast[ind], 1));
		}
	}
	for(int i=0;i<n+m;++i) {
		if(indeg[i]==0&&!b[i]) {
			//cerr<<i<<" "<<indeg[i]<<"\n";
			dfs(i);
		}
	}
	
	if(ok) {
		cout<<"YES\n";
		for(int i=0;i<n;++i) cout<<ans[get(i)]<<" ";cout<<"\n";
		for(int i=n;i<n+m;++i) cout<<ans[get(i)]<<" ";cout<<"\n";
	
		
	}else cout<<"NO\n";
	
	

}
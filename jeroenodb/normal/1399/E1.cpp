#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5;

struct edge {
	int p,w;
};

int children[mxN+1]={};
vector<pair<int,int>> adj[mxN+1];
priority_queue<edge> pq;
long long dfs(int at, int from) {
	//D(at);D(from);
	long long ans = 0;
	for(auto p:adj[at]) {
		int to = p.first;
		if(to==from) continue;
		ans+=dfs(to,at)+(long long)p.second*children[to];
		children[at]+=children[to];
		pq.push({to,p.second});
	}
	if(children[at]==0) children[at]=1;
	//D(at);D(children[at]);
	return ans;
}

bool operator<(const edge& a, const edge& b) {
	return (long long)(a.w-a.w/2)*children[a.p] <(long long)(b.w-b.w/2)*children[b.p];
}
edge es[mxN];
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		long long s;
		cin >> n >> s;
		pq = priority_queue<edge>();
		memset(children,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;++i) adj[i].clear();
		for(int i=0;i<n-1;++i) {
			int u,v,w;
			cin >> u >> v >> w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		long long cur = dfs(1,-1);
		//D(cur);
		int ans = 0;
		while(cur>s) {
			ans++;
			edge best = pq.top();pq.pop();
			//D(best.w);D(best.p);
			cur-=(long long)(best.w-best.w/2)*children[best.p];
			best.w=best.w/2;
			if(best.w!=0) pq.push(best);
		}
		cout << ans << endl;
	}
}
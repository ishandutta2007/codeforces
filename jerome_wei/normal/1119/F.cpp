#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 5e5+5;
typedef long long ll;
int deg[N];

vector<int> Node[N], curNode[N];

typedef pair<ll,ll> pil;
vector<pil> G[N];

int presant[N];

set<pil> S[N];

bool dft[N];
ll f[N][2];
int Limit;
ll cur[N];
bool vis[N];
#define to first
#define val second
bool cmp (const pil a,const pil b){return deg[a.first] < deg[b.first];}

inline void dfs(int x,int pre){
	vis[x] = 1;
	set<pil> ins,del;
	ins.clear(),del.clear();
	while(presant[x] < (int)G[x].size() && deg[G[x][presant[x]].to] <= Limit){
		cur[x] += G[x][presant[x]].val;
		S[x].insert(pil(G[x][presant[x]].val,G[x][presant[x]].to));
		presant[x]++;
	}
	while((int)S[x].size() > deg[x] - Limit) {
		cur[x] -= (*--S[x].end()).first;
		S[x].erase(*--S[x].end());
	}
	ll ret = 0;
	for(size_t i=presant[x];i<G[x].size();i++){
		int v = G[x][i].to;if(v==pre)continue;
		dfs(v,x);
		ret += f[v][0];
		cur[x] += f[v][1] - f[v][0] + G[x][i].val;
		ins.insert(pil(f[v][1] - f[v][0] + G[x][i].val,v));
		S[x].insert(pil(f[v][1] - f[v][0] + G[x][i].val,v));
	}
	while((int)S[x].size() > deg[x] - Limit) {
		if((*--S[x].end()).first <= 0)break;
		cur[x] -= (*--S[x].end()).first;
		del.insert(*--S[x].end());
		S[x].erase(*--S[x].end());
	}
	f[x][0] = ret + cur[x];
	f[x][1] = ret + cur[x] - max(0ll,(*--S[x].end()).first);
//	cout << x << ": " << f[x][1] << ", " << f[x][0] << endl;
	set<pil> :: iterator itt;
	for(itt = del.begin();itt!=del.end();itt++){
		cur[x] += (*itt).first;
		S[x].insert(*itt);
	}
	for(itt = ins.begin();itt!=ins.end();itt++){
		cur[x] -= (*itt).first;
		S[x].erase(*itt);
	}
}

int main()
{
	cin >> n;
	ll tot = 0;
	for(int i=1;i<n;i++){
		int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
		++deg[u],++deg[v];
		G[u].push_back(pil(v,w));
		G[v].push_back(pil(u,w));
		tot+=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<deg[i];j++)Node[j].push_back(i);
		sort(G[i].begin(),G[i].end(),cmp);
	}
	printf("%lld\n",tot);
	for(int k=1;k<n;k++){
		Limit = k;
		ll ans = 0;
		for(size_t i=0;i<Node[k].size();i++){
			int x = Node[k][i];
			if(!vis[x]){
//				cout << " from " << x << " to start---" << endl;
				dfs(x,0);
				ans += f[x][0];
			}
		}
		for(size_t i=0;i<Node[k].size();i++){
			int x = Node[k][i];
			vis[x] = 0;
		}
		printf("%lld\n",ans);
	}
}
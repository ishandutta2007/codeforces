#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
const int MAXN = 100005;
const int MAXT = 700005;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<int, int>;

struct node{
	int pos, len, frm;
	bool operator<(const node &n)const{
		return n.len < len;
	}
};

int n, m;
vector<pi> gph[MAXN];
int dist[MAXN], prv[MAXN], parg[MAXN], trnode[MAXN];

int trie[MAXT][10], par[MAXT], pae[MAXT], dep[MAXT], piv;
string itos(int x){
	string ans;
	while(x){
		ans.push_back(x % 10 + '0');
		x /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int spt[20][MAXT];

void makeAnc(int v){
	spt[0][v] = par[v];
	for(int i=1; i<20; i++){
		assert(spt[i-1][v] >= 0);
		spt[i][v] = spt[i-1][spt[i-1][v]];
	}
}

bool cmp(int node1, int edge1, int node2, int edge2){
	string s = itos(edge1);
	string t = itos(edge2);
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	node1 = trnode[node1];
	node2 = trnode[node2];
	while(dep[node1] > dep[node2]){
		s.push_back(pae[node1]);
		node1 = par[node1];
	}
	while(dep[node1] < dep[node2]){
		t.push_back(pae[node2]);
		node2 = par[node2];
	}
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	if(node1 != node2){
		for(int i=19; i>=0; i--){
			if(spt[i][node1] != spt[i][node2]){
				node1 = spt[i][node1];
				node2 = spt[i][node2];
			}
		}
		return pae[node1] < pae[node2];
	}
	return s < t;
}

int ans[MAXT];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].emplace_back(i, e);
		gph[e].emplace_back(i, s);
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	priority_queue<node> pq;
	pq.push({1, 0, 0});
	bool vis[MAXN] = {};
	while(!pq.empty()){
		auto x = pq.top(); pq.pop();
		if(x.frm != prv[x.pos] || x.len != dist[x.pos]) continue;
		vis[x.pos] = 1;
		int pos = trnode[parg[x.pos]];
		string ff = itos(x.frm);
		for(auto &i : ff){
			if(!trie[pos][i - '0']){
				trie[pos][i - '0'] = ++piv;
				par[trie[pos][i - '0']] = pos;
				pae[trie[pos][i - '0']] = i;
				dep[trie[pos][i - '0']] = dep[pos] + 1;
				makeAnc(trie[pos][i - '0']);
			}
			pos = trie[pos][i - '0'];
		}
		trnode[x.pos] = pos;
		for(auto &i : gph[x.pos]){
			int L = sz(itos(i.first));
			if(dist[i.second] > L + x.len ||
					(dist[i.second] == L + x.len && 
					 cmp(x.pos, i.first, parg[i.second], prv[i.second]))){
				dist[i.second] = L + x.len;
				prv[i.second] = i.first;
				parg[i.second] = x.pos;
				pq.push({i.second, dist[i.second], prv[i.second]});
			}
		}
	}
	for(int i=1; i<=piv; i++){
		ans[i] = (ans[par[i]] * 10ll + pae[i] - 48)% mod;
	}
	for(int i=2; i<=n; i++) printf("%d\n", ans[trnode[i]]);
}
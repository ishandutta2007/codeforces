#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 2005;
const int MAXT = 1000005;
const int mod = 1e9 + 7;

int n, k;
int trie[MAXT][26], term[MAXT], cnt;
int dfn[MAXT], dout[MAXT], par[MAXT], dep[MAXT], piv;
vector<int> v;

bool in(int s, int t){
	return dfn[s] <= dfn[t] && dout[t] <= dout[s];
}

void dfs(int x){
	dfn[x] = ++piv;
	if(term[x]) v.push_back(x);
	for(int i=0; i<26; i++){
		if(trie[x][i]) dfs(trie[x][i]);
	}
	dout[x] = piv;
}


int lca(int x, int y){
	while(dep[x] < dep[y]) y = par[y];
	while(dep[x] > dep[y]) x = par[x];
	while(x != y){
		x = par[x];
		y = par[y];
	}
	return x;
}

vector<pi> gph[2 * MAXN];
lint dp[2 * MAXN][2 * MAXN];
int sz[2 * MAXN];

void dfs2(int x){
	sz[x] = term[v[x]];
	for(auto &i : gph[x]){
		dep[i.second] = dep[x] + i.first;
		dfs2(i.second);
		sz[x] += sz[i.second];
	}
}

int main(){
	char buf[505];
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%s", buf);
		int p = 0;
		for(int j=0; buf[j]; j++){
			if(!trie[p][buf[j] - 'a']){
				trie[p][buf[j] - 'a'] = ++cnt;
				par[cnt] = p;
				dep[cnt] = dep[p] + 1;
			}
			p = trie[p][buf[j] - 'a'];
		}
		term[p]++;
	}
	dfs(0);
	sort(v.begin(), v.end(), [&](const int &a, const int &b){
		return dfn[a] < dfn[b];
	});
	v.push_back(0);
	{
		int sz = v.size();
		for(int i=0; i+1<sz; i++){
			v.push_back(lca(v[i], v[i+1]));
		}
	}
	sort(v.begin(), v.end(), [&](const int &a, const int &b){
		return dfn[a] < dfn[b];
	});
	v.resize(unique(v.begin(), v.end()) - v.begin());
	stack<int> stk;
	for(int i=0; i<v.size(); i++){
		while(!stk.empty() && !in(v[stk.top()], v[i])) stk.pop();
		if(i > 0) gph[stk.top()].push_back(pi(dep[v[i]] - dep[v[stk.top()]], i));
		stk.push(i);
	}
	dfs2(0);
	for(int i=v.size() - 1; i>=0; i--){
		for(int j=0; j<=term[v[i]]; j++) dp[i][j] = 1ll * j * (j-1) / 2 * dep[i];
		int cur = term[v[i]];
		for(auto &j : gph[i]){
			lint nxt[2 * MAXN] = {};
			for(int k=0; k<=sz[j.second]; k++){
				for(int l=0; l<=cur; l++){
					nxt[k + l] = max(nxt[k + l], dp[j.second][k] + dp[i][l] + 1ll * k * l * dep[i]);
				}
			}
			memcpy(dp[i], nxt, sizeof(nxt));
			cur += sz[j.second];
		}
	}
	cout << dp[0][k];
}
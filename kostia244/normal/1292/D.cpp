#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define less more
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 10050;
using node = array<int, 669>;
vector<int> pr;
map<node, int> id;
int p[maxn], dep[maxn], factid[maxn], cnt[maxn];
node lca(node &p, node &c) {
	node res{};
	int i = 0;
	while(i < 669 && p[i] == c[i]) res[i] = p[i], i++;
	if(i < 669) res[i] = min(p[i], c[i]);
	return res;
}
bool par(node &p, node &c) {
	return lca(p, c) == p;
}
ll debug(node x) {
	ll a = 1;
	for(int i = 0; i < 669; i++) while(x[i]--) a *= pr[i];
	return a;
}

vector<array<int, 2>> G[maxn];
ll init = 0, sub_sz[maxn];
ll dfs(int v, int p, ll dep) {
	ll sm = dep*cnt[v];
	sub_sz[v] = cnt[v];
	for(auto &[i, w] : G[v]) if(i ^ p) {
		sm += dfs(i, v, dep+w);
		sub_sz[v] += sub_sz[i];
	}
	return sm;
}
ll ans = 1ll<<60;
void comp(int v, int p, ll cur) {
	ans = min(ans, cur);
	for(auto [i, w] : G[v]) if(i ^ p) {
		comp(i, v, cur + w*(sub_sz[0]-2*sub_sz[i]));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 2; i <= 5000; i++) {
		int ok = 1;
		for(int j = 2; j*j <= i; j++) ok &= i%j > 0;
		if(ok) pr.push_back(i);
	}
	reverse(all(pr));
	node cur{};
	vector<pair<node, int>> st;
	fill(all(p), -1);
	for(int i = 1; i <= 5000; i++) {
		int ti = i;
		for(int k = 0; k < pr.size(); k++) {
			while(ti%pr[k] == 0) ti /= pr[k], cur[k]++;
		}
		while(st.size() > 1 && !par(st[st.size()-2].first, cur)) {
			st.pop_back();
		}
		if(st.size() > 1 && !par(st.back().first, cur)) {
			auto [f, fid] = st.back(); st.pop_back();
			auto lc = lca(f, cur);
			if(st.back().first != lc) {
				int x = id.size();
				id[lc] = x;
				p[x] = st.back().second;
				p[fid] = x;
				st.push_back(pair<node, int>{lc, x});
			}
		}
		int x = id.size();
		id[cur] = x;
		if(st.size()) {
			p[x] = st.back().second;
		}
		st.push_back({cur, x});
		factid[i] = x;
	}
	for(auto &i : id) {
		for(auto j : i.first) dep[i.second] += j;
	}
	int N = id.size();
	for(int i = 1; i < N; i++) {
		G[p[i]].push_back({i, dep[i]-dep[p[i]]});
		G[i].push_back({p[i], dep[i]-dep[p[i]]});
	}
	
	int n, t;
	for(cin >> n; n--;) { cin >> t, cnt[factid[t]]++; }
	init = dfs(0, 0, 0);
	comp(0, 0, init);
	cout << ans << '\n';
}
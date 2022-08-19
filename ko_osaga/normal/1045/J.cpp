#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
using lint = long long;
typedef pair<lint, int> pii;
const int MAXN = 100005;
const int mod1 = 1e9 + 409;
const int mod2 = 1e9 + 433;

pii sor[10000005];
int n, q, Z;
int par[17][MAXN], dep[MAXN], sz[MAXN];
int dfn[MAXN], chn[MAXN], piv;
char pae[MAXN], buf[105];
vector<pi> gph[MAXN];

void dfs(int x){
	sz[x] = 1;
	for(auto &i : gph[x]){
		dep[i.second] = dep[x] + 1;
		par[0][i.second] = x;
		pae[i.second] = i.first;
		gph[i.second].erase(find(gph[i.second].begin(), gph[i.second].end(), pi(i.first, x)));
		dfs(i.second);
		sz[x] += sz[i.second];
	}
}

void hld(int x){
	dfn[x] = ++piv;
	if(gph[x].empty()) return;
	chn[gph[x][0].second] = chn[x];
	hld(gph[x][0].second);
	for(int i=1; i<gph[x].size(); i++){
		chn[gph[x][i].second] = gph[x][i].second;
		hld(gph[x][i].second);
	}
}

int anc(int s, int v){
	for(int i=0; i<17; i++){
		if((v >> i) & 1) s = par[i][s];
	}
	return s;
}

int lca(int s, int e){
	if(dep[s] < dep[e]) swap(s, e);
	s = anc(s, dep[s] - dep[e]);
	for(int i=16; i>=0; i--){
		if(par[i][s] != par[i][e]){
			s = par[i][s];
			e = par[i][e];
		}
	}
	if(s != e) return par[0][s];
	return s;
}

lint getHash(string s){
	lint h1 = 0, h2 = 0;
	for(auto &i : s){
		h1 = ((h1 << 8) + h1) + i;
		h2 = ((h2 << 8) + h2) + i;
		h1 %= mod1;
		h2 %= mod2;
	}
	return h1 * mod2 + h2;
}

int kmp(string s, string t){
	vector<int> fail(s.size() + 1);
	int p = 0;
	for(int i=1; i<s.size(); i++){
		while(p && s[i] != s[p]) p = fail[p];
		if(s[i] == s[p]) p++;
		fail[i + 1] = p;
	}
	p = 0;
	int ans = 0;
	for(int i=0; i<t.size(); i++){
		while(p && t[i] != s[p]) p = fail[p];
		if(t[i] == s[p]) p++;
		if(p == s.size()){
			ans++;
			p = fail[p];
		}
	}
	return ans;
}

int up(int x, int y, lint h, int l){
	int ans = 0;
	while(chn[x] != chn[y]){
		int st = dfn[chn[x]];
		int ed = dfn[x];
		ans += upper_bound(sor, sor + Z, pii(h, ed)) - lower_bound(sor, sor + Z, pii(h, st));
		x = par[0][chn[x]];
	}
	int st = dfn[y] + 1;
	int ed = dfn[x];
	ans += upper_bound(sor, sor + Z, pii(h, ed)) - lower_bound(sor, sor + Z, pii(h, st));
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d %s",&s,&e,buf);
		gph[s].emplace_back(*buf, e);
		gph[e].emplace_back(*buf, s);
	}
	dfs(1);
	for(int i=1; i<=n; i++){
		sort(gph[i].begin(), gph[i].end(), [&](const pi &a, const pi &b){
			return sz[a.second] > sz[b.second];
		});
	}
	for(int i=1; i<17; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
	chn[1] = 1;
	hld(1);
	for(int i=2; i<=n; i++){
		int ptr = i;
		lint h1 = 0, h2 = 0;
		for(int j=1; j<=100; j++){
			if(ptr == 1){
				continue;
			}
			h1 = ((h1 << 8) + h1) + pae[ptr];
			h2 = ((h2 << 8) + h2) + pae[ptr];
			h1 %= mod1; h2 %= mod2;
			sor[Z++] = pii(h1 * mod2 + h2, dfn[i]);
			ptr = par[0][ptr];
		}
	}
	sort(sor, sor + Z);
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		int s, e;
		scanf("%d %d %s",&s,&e,buf); 
		int l = lca(s, e);
		int ns = anc(s, max(0, dep[s] - dep[l] - 100));
		int ne = anc(e, max(0, dep[e] - dep[l] - 100));
		string str = buf;
		lint fwHash = getHash(str);
		reverse(str.begin(), str.end());
		lint bwHash = getHash(str);
		reverse(str.begin(), str.end());
		int ans = up(s, ns, fwHash, str.size()) + up(e, ne, bwHash, str.size());
		string L, R;
		while(ns != l){
			L.push_back(pae[ns]);
			ns = par[0][ns];
		}
		while(ne != l){
			R.push_back(pae[ne]);
			ne = par[0][ne];
		}
		reverse(R.begin(), R.end());
		ans += kmp(str, L + R);
		printf("%d\n", ans);
	}
}
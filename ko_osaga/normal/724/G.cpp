#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, lint> pi;
const int mod = 1e9 + 7;

int n, m;

vector<pi> gph[100005];
int col[100005];
lint cnt[3], bad;

lint nc2(lint x){
	return ((x * (x - 1)) / 2) % mod;
}

void dfs(int x, int c, int p){
	if(col[x]){
		if(col[x] != c) bad = 1;
		return;
	}
	col[x] = c;
	cnt[c]++;
	for(auto &i : gph[x]){
		if((i.second >> p) & 1) dfs(i.first, 3 - c, p);
		else dfs(i.first, c, p);
	}
}

bool vis[100005];
vector<lint> v;
lint dep[100005];

void dfs2(int x, int p, lint xv){
	if(vis[x]) return;
	vis[x] = 1;
	dep[x] = xv;
	for(auto &i : gph[x]){
		if(i.first == p) continue;
		if(vis[i.first]){
			lint w = dep[i.first] ^ xv ^ i.second;
			if(w) v.push_back(w);
		}
		else{
			dfs2(i.first, x, xv ^ i.second);
		}
	}
}

lint free_bit[100005];

void dfs3(int x, lint v){
	if(free_bit[x]) return;
	free_bit[x] = v;
	for(auto &i : gph[x]){
		dfs3(i.first, v);
	}
}

int getrank(vector<lint> &v){
	lint basis[60] = {};
	for(auto &i : v){
		for(int j=59; j>=0; j--){
			if((i >> j) & 1){
				if(basis[j]){
					i ^= basis[j];
				}
				else{
					basis[j] = i;
					break;
				}
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<60; i++){
		if(basis[i]) cnt++;
	}
	return cnt;
}

lint solve(){
	lint ret = 0, inv = (mod + 1) / 2;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			v.clear();
			dfs2(i, -1, 0);
			dfs3(i, (1ll << getrank(v)) % mod);
		}
	}
	lint ipow = 1;
	for(int i=0; i<60; i++){
		memset(col, 0, sizeof(col));
		for(int j=1; j<=n; j++){
			if(!col[j]){
				bad = 0;
				cnt[1] = cnt[2] = 0;
				dfs(j, 1, i);
				if(bad){
					ret += (nc2(cnt[1] + cnt[2]) * free_bit[j] % mod) * (inv * ipow % mod) % mod;
				}
				else{
					ret += (cnt[1] * cnt[2] % mod) * (ipow * free_bit[j] % mod) % mod;
				}
				ret %= mod;
			}
		}
		ipow *= 2;
		ipow %= mod;
	}
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e; lint x;
		scanf("%d %d %lld",&s,&e,&x);
		gph[s].push_back(pi(e, x));
		gph[e].push_back(pi(s, x));
	}
	cout << solve();
}
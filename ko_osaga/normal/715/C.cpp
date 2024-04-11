#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int n, mod, inv;
vector<pi> gph[100005];

int sz[100005], msz[100005], vis[100005];
vector<int> dfn;

void dfs(int x, int p){
	sz[x] = 1; msz[x] = 0;
	for(auto &j : gph[x]){
		if(j.second == p || vis[j.second]) continue;
		dfs(j.second, x);
		sz[x] += sz[j.second];
		msz[x] = max(msz[x], sz[j.second]);
	}
	dfn.push_back(x);
}

int get_center(int x){
	dfn.clear();
	dfs(x, -1);
	int cur = 1e9, ret = -1;
	for(auto &i : dfn){
		int v = max(msz[i], (int)dfn.size() - sz[i]);
		if(v < cur){
			cur = v;
			ret = i;
		}
	}
	return ret;
}

void dfs2(int x, int p, vector<int> &ret, lint cur, lint pw){
	ret.push_back(cur);
	for(auto &i : gph[x]){
		if(vis[i.second]) continue;
		if(i.second == p) continue;
		dfs2(i.second, x, ret, (cur + 1ll * pw * i.first) % mod, (10ll * pw) % mod);
	}
}

void dfs3(int x, int p, vector<int> &ret, lint cur, lint cinv){
	ret.push_back(1ll * cur * cinv % mod);
	for(auto &i : gph[x]){
		if(vis[i.second]) continue;
		if(i.second == p) continue;
		dfs3(i.second, x, ret, (10ll * cur + i.first) % mod, (1ll * cinv * inv) % mod);
	}
}

lint countf(vector<int> &v1, vector<int> &v2){
	lint ret = 0;
	for(int i=0; i<v1.size(); i++){
		int nxt = mod - v1[i];
		nxt %= mod;
		ret += upper_bound(v2.begin(), v2.end(), nxt) - lower_bound(v2.begin(), v2.end(), nxt);
	}
	return ret;
}

int main(){
	cin >> n >> mod;
	if(mod == 1){
		printf("%lld\n", 1ll * n * (n-1));
		return 0;
	}
	inv = mul_inv(10 % mod, mod);
	for(int i=0; i<n-1; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		gph[s].push_back(pi(x, e));
		gph[e].push_back(pi(x, s));
	}
	lint ret = 0;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		auto x = que.front();
		que.pop();
		x = get_center(x);
		vis[x] = 1;
		vector<int> vl, vr;
		for(auto &j : gph[x]){
			if(vis[j.second]) continue;
			que.push(j.second);
			vector<int> tvl, tvr;
			dfs2(j.second, x, tvl, j.first % mod, 10 % mod);
			dfs3(j.second, x, tvr, j.first % mod, inv);
			sort(tvl.begin(), tvl.end());
			sort(tvr.begin(), tvr.end());
			ret -= countf(tvl, tvr);
			for(auto &i : tvl) vl.push_back(i);
			for(auto &i : tvr) vr.push_back(i);
		}
		sort(vl.begin(), vl.end());
		sort(vr.begin(), vr.end());
		ret += countf(vl, vr);
		ret += count(vl.begin(), vl.end(), 0);
		ret += count(vr.begin(), vr.end(), 0);
	}
	cout << ret;

}
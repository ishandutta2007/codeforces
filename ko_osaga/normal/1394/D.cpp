#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const lint inf = 1e12;
const int MAXN = 500005;

vector<int> gph[MAXN];
lint up[MAXN], dn[MAXN];
lint t[MAXN], h[MAXN];

void dfs(int x, int p){
	vector<pi> v;
	lint tot = 0;
	lint sum = 0;
	for(auto &i : gph[x]){
		if(i != p){
			dfs(i, x);
			if(h[i] > h[x]) up[i] = -inf;
			if(h[i] < h[x]) dn[i] = -inf;
			v.emplace_back(up[i], dn[i]);
			sum += up[i];
		}
	}
	sort(all(v), [&](const pi &a, const pi &b){
		return a.second - a.first > b.second - b.first;
	});
	up[x] = dn[x] = -inf;
	// compute up[x] : one out start
	{
		lint foo = sum;
		int in = sz(gph[x]) - 1, out = 1;
		up[x] = max(up[x], foo + min(in, out) * t[x]);
		for(auto &i : v){
			foo += i.second - i.first;
			in--;
			out++;
			up[x] = max(up[x], foo + min(in, out) * t[x]);
		}
	}
	// compute dn[x] : all in start
	{
		lint foo = sum;
		int in = sz(gph[x]), out = 0;
		dn[x] = max(dn[x], foo + min(in, out) * t[x]);
		for(auto &i : v){
			foo += i.second - i.first;
			in--;
			out++;
			dn[x] = max(dn[x], foo + min(in, out) * t[x]);
		}
	}
}

lint solve(){
	vector<pi> v;
	lint sum = 0;
	int x = 1;
	for(auto &i : gph[1]){
		dfs(i, 1);
			if(h[i] > h[x]) up[i] = -inf;
			if(h[i] < h[x]) dn[i] = -inf;
		v.emplace_back(up[i], dn[i]);
		sum += up[i];
	}
	sort(all(v), [&](const pi &a, const pi &b){
			return a.second - a.first > b.second - b.first;
			});
	lint foo = sum;
	int in = sz(gph[x]), out = 0;
	lint dap = -inf;
	dap = max(dap, foo + min(in, out) * t[x]);
	for(auto &i : v){
		foo += i.second - i.first;
		in--;
		out++;
		dap = max(dap, foo + min(in, out) * t[x]);
	}
	return dap;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&t[i]);
	for(int i=1; i<=n; i++) scanf("%lld",&h[i]);
	for(int i=1; i<n; i++){
		int u, v; scanf("%d %d",&u,&v);
		gph[u].push_back(v);
		gph[v].push_back(u);
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		ret += 1ll * sz(gph[i]) * t[i];
	}
	cout << ret - solve() << endl;
}
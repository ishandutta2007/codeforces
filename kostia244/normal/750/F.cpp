#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define stack loli
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, inf = 1<<26;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int root = -1, h;
map<int, vector<int>> g;
int qry = 0;
vector<int> rg[maxn];
vector<int> get_g(int v) {
	if(g.count(v)) return g[v];
    if(++qry == 17) {
        root = v;
        return {};
    }
	cout << "? " << v << endl;
	//if(rg[v].size() == 2) root = v;
	//return g[v] = rg[v];
	
	int k;
	cin >> k;
	if(k == 0) exit(0);
	if(k == 2) root = v;
	g[v].resize(k);
	for(auto &i : g[v]) cin >> i;
	//shuffle(all(g[v]), rng);
	return g[v];
}
vector<int> stack, vis;
void go(int v) {
	if(root != -1) return;
	get_g(v);
	if(root != -1) return;
	vis[v] = 1;
	stack.push_back(v);
	for(auto i : get_g(v)) if(!vis[i]) {
		//cout << v << " -> " << i << endl;
		go(i);
		return;
	}
}
void dig(int v, int d) {
	if(root != -1) return;
	get_g(v);
	if(root != -1) return;
	vis[v] = 1;
	if(d)
	for(auto i : get_g(v)) if(!vis[i]) {
		dig(i, d-1);
		//return;
	}
}
void solve() {
    qry = 0;
	cin >> h;root = -1;
	/*for(int f, t, i = 2; i < 1<<h; i++) {
		cin >> f >> t;
		rg[f].push_back(t);
		rg[t].push_back(f);
	}*/
	if(h == 0) exit(0);
	g.clear();
	vis.assign(1<<h, 0);
	stack.clear();
	get_g(1);
	if(root != -1) {
		cout << "! " << root << endl;
		return;
	}
	int v = -1;
	if(get_g(1).size() == 1) {
		stack.push_back(1);
		vis[1] = 1;
		v = get_g(1)[0];
	} else {
		go(1);
		reverse(all(stack));
		if(root != -1) {
			cout << "! " << root << endl;
			return;
		}
		if(get_g(1).size() > 1) {
			stack.pop_back();
			go(1);
			if(root != -1) {
				cout << "! " << root << endl;
				return;
			}
		}
		v = stack.size()/2;
		assert(stack.size()>1);
		assert(stack.size()&1);
		while(v--) stack.pop_back();
		for(auto i : get_g(stack.back())) {
			//cout << stack.back() << " -> " << i << " " << vis[i] << endl;
			if(!vis[i]) v = i;
		}
	}
	//cout << "CP1" << " " << v << endl;
	if(root != -1) {
		cout << "! " << root << endl;
		return;
	}
	while(true) {
		if(h-stack.size()-1>2)
			go(v);
		else
			dig(v, h-stack.size()-1), assert(root != -1);
		if(root != -1) {
			cout << "! " << root << endl;
			return;
		}
		v = stack.size()/2;
		assert(stack.size()>1);
		assert(stack.size()&1);
		while(v--) stack.pop_back();
		for(auto i : get_g(stack.back())) if(!vis[i]) v = i;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
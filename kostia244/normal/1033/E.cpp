#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define left trigged
#define right lol
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 666;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;

int local = 0;
vector<array<int, 2>> edges;


int ask(vector<int> a) {
	cout << "? " << a.size() << " ";
	for(auto &i : a) cout << i << " "; cout << endl;
	int k = 0;
	if(local) {
		for(auto [x, y] : edges) k += count(all(a), x) && count(all(a), y);
		cout << "= " << k << endl;
	} else cin >> k;
	return k;
}
vector<int> g[maxn];
vector<int> st;
bool dfs(int v, int p, int t) {
	st.push_back(v);
	if(v == t) return true;
	for(auto i : g[v]) if(i != p) {
		if(dfs(i, v, t)) return true;
	}
	st.pop_back();
	return false;
}
void solve() {
	vector<int> vis(n+1), a, asz;
	while(a.size() < n) {
		vector<int> b;
		for(int j = 0, i = 1; i <= n; i++)
			if(!vis[i]) b.push_back(i);
			else j++;
		int pos = 0;
		for(int z = 1<<10; z>>=1;) {
			vector<int> q = a, p; 
			if(pos+z > b.size()) continue;
			for(int i = 0; i < pos+z; i++) {
				p.push_back(b[i]);
				q.push_back(b[i]);
			}
			if(ask(q) == ask(p)+(asz.empty()?0:asz.back())) pos += z;
		}
		if(pos == b.size()) {//new component
			vis[b[0]] = 1;
			a.push_back(b[0]);
		} else {
			int x = b[pos];
			pos = 0;
			for(int z = 1<<10; z>>=1;) {
				vector<int> q {x}; 
				if(pos+z > a.size()) continue;
				for(int i = 0; i < pos+z; i++) q.push_back(a[i]);
				if(ask(q) == asz[pos+z-1]) pos += z;
			}
			int y = a[pos];
			a.push_back(x);
			vis[x] = 3^vis[y];
			g[x].push_back(y);
			g[y].push_back(x);
		}
		asz.push_back(ask(a));
	}
	vector<int> left, right;
	for(int i = 1; i <= n; i++) (vis[i] == 1 ? left : right).push_back(i);
	if(left.size() && right.size()) {
		if(!ask(right)) swap(left, right);
		int x = -1;
		while(ask(right)) {
			x = right.back(); right.pop_back();
		}
		if(x != -1) {
			int y = -1;
			for(auto i : right) if(ask({x, i})) {y = i; break;}
			assert(y != -1);
			dfs(x, x, y);
			cout << "N " << st.size() << endl;
			for(auto i : st) cout << i << " "; cout << endl;
			exit(0);
		}
	}
	if(left.empty()) swap(left, right);
	cout << "Y " << left.size() << endl;
	for(auto &i : left) cout << i << " ";cout << endl;
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	if(local) {
		int m,x,y;
		for(cin>>m;m--;)cin>>x>>y,edges.push_back({x,y});
	}
	solve();
}
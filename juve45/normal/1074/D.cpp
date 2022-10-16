#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 400100;
const int L = 21;
int n, jmp[N][L + 1], cost[N][L + 1], arb[N], d[N], sz[N], l, r, x;
vector <pair<int, int> > v[N];

void dfs(int node, int ant, int dpth, int c) {
	// dbg(node, ant, dpth, c, arb[ant]);

	sz[arb[node]]--;
	arb[node] = arb[ant];
	// dbg(arb[node]);
	// c[arb[node]].push_back(node);
	sz[arb[node]]++;
	d[node] = dpth;

	memset(jmp[node], -1, sizeof jmp[node]);
	memset(cost[node], -1, sizeof cost[node]);
	jmp[node][0] = ant;
	cost[node][0] = c;

	for(int i = 1; i <= L; i++) {
		// dbg(i);
		if(jmp[node][i - 1] == -1) jmp[node][i] = -1, cost[node][i] = cost[node][i - 1];
		else {
			jmp[node][i] = jmp[jmp[node][i - 1]][i - 1];
			cost[node][i] = (cost[node][i - 1] ^ cost[jmp[node][i - 1]][i - 1]);
		}
	}
	// dbg(node);
	// dbg_v(jmp[node], 5);

	for(auto i : v[node])
		if(i.st != ant)
			dfs(i.st, node, dpth + 1, i.nd);
}


int LCA(int x, int y) {
	if(d[x] < d[y]) swap(x, y);

	// dbg(x, y);
	int tot_cost = 0;
	// dbg(x, y, d[x], d[y]);
	// dbg_v(jmp[x], 5);
	for(int i = L; i >= 0; i--) {
		if(jmp[x][i] == -1) continue;
		
		if(d[jmp[x][i]] >= d[y]) {
			tot_cost ^= cost[x][i];
			x = jmp[x][i];
		}
	}
	// dbg(x, y, d[x], d[y]);

	assert(d[x] == d[y]);
	
	if(x != y) {
		for(int i = L; i >= 0; i--) {
			if(jmp[x][i] == -1 || jmp[y][i] == -1) continue;
			if(jmp[x][i] == jmp[y][i]) continue;

			tot_cost ^= cost[x][i];
			tot_cost ^= cost[y][i];
			x = jmp[x][i];
			y = jmp[y][i];
		}
		// dbg(x, y);
		assert(x != y);
		tot_cost ^= cost[x][0];
		tot_cost ^= cost[y][0];
		x = jmp[x][0];
		y = jmp[y][0];
	}
	assert(x == y);
	return tot_cost;
}

int que(int x, int y) {
	// dbg(x, y, arb[x], arb[y]);
	if(arb[x] != arb[y]) return -1;
	// dbg(x, y, d[x], d[y]);

	return LCA(x, y);
}

void unite(int x, int y, int c) {

	if(arb[x] == arb[y]) {
		return;
		if(que(x, y) != c) return;
	}

	if(sz[arb[x]] > sz[arb[y]]) swap(x, y);
	// pe x il duc in y;
	// dbg(x, arb[x], sz[arb[x]]);
	// dbg(y, arb[y], sz[arb[y]]);

	v[x].push_back({y, c});
	v[y].push_back({x, c});

	dfs(x, y, d[y] + 1, c);
}

map <int, int> mp;

int go(int l) {
	if(mp.count(l)) return mp[l];
	int k = mp.size() + 1;
	mp[l] = k;
	return k;
}

int main() {
	ios_base::sync_with_stdio(false);
	// n = 10;
	cin >> n;
	for(int i= 1; i < N; i++) arb[i] = i, sz[i] = 1;
	memset(jmp, -1, sizeof jmp);

	// unite(1, 2, 3);
	// unite(2, 3, 1);
	// unite(3, 5, 8);
	// dbg_v(d, 4);
	// dbg(que(1, 5));
	int last = 0, op;
	for(int i = 1; i <= n; i++) {
		cin >> op; 
		if(op == 1) {
			cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if(l > r) swap(l, r);
			r++;
			l = go(l);
			r = go(r);
			unite(l, r, x);
		} else {
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if(l > r) swap(l, r);
			r++;
			l = go(l);
			r = go(r);
			int ret = que(l, r);
			if(ret == -1) last = 1;
			else last = ret;
			cout << ret << '\n';
		}
	}
}
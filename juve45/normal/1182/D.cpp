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

const int N = 100100;
int n, use[N], done[N], a, b, root[N], gr[N], head, tail, lvlmax;
vector <int> v[N], road, lst[N];

bool dfs(int node, int lvl) {
	// dbg(node, lvl);
	use[node] = 1;
	if(!gr[lvl])
		gr[lvl] = v[node].size();
	else if(gr[lvl] != v[node].size())
		return 0;

	for(auto i : v[node])
		if(!use[i] && !dfs(i, lvl + 1))
			return 0;

	return 1;
}

bool check(int root) {
	memset(use, 0, sizeof use);
	memset(gr, 0, sizeof gr);
	return dfs(root, 0);
}


void diam(int node, int lvl) {
	// dbg(node, lvl);
	// dbg(v[node]);
	use[node] = lvl;
	if(lvl > use[lvlmax]) lvlmax = node;

	for(auto i : v[node])
		if(!use[i])
			diam(i, lvl + 1);
}

bool get_road(vector <int> &r, int from, int to) {
	// dbg(from);
	if(from == to) {
		r.push_back(from);
		return 1;
	}

	use[from] = 1;
	for(auto i : v[from])
		if(!use[i] && get_road(r, i, to)) {
			r.push_back(from);
			return 1;
		}
	return 0;
}

pair<int, int> dfs2(int node, int lvl = 1) {
	use[node] = 1;
	if(v[node].size() == 1) return {lvl, node};

	if(v[node].size() > 2) return {0, -1};
	for(auto i : v[node])
		if(!use[i])
			return dfs2(i, lvl + 1);
	return {0, -1};
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;

	if(n == 1) {
		cout << "1\n";
		return 0;
	}

	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	lvlmax = 0;
	memset(use, 0, sizeof use);
	diam(1, 1);

	head = lvlmax;
	// dbg(head);
	lvlmax = 0;
	memset(use, 0, sizeof use);
	diam(head, 1);
	tail = lvlmax;

	// dbg(tail);
	memset(use, 0, sizeof use);
	get_road(road, head, tail);
	
	// dbg(road);

	int cand = road[road.size() / 2];
	// dbg(cand);
	if(check(cand)) return cout << cand << '\n', 0;

	memset(use, 0, sizeof use);
	use[cand] = 1;
	int cnt1 = 0, cnt2 = 0;
	// dbg(v[cand]);
	for(auto i : v[cand]) {
		auto p = dfs2(i);
		// dbg(i, p);
		lst[p.st].push_back(p.nd);
		if(lst[p.st].size() == 2) cnt2++, cnt1--;
		if(lst[p.st].size() == 1) cnt1++;
	}
	// dbg(cnt1, cnt2);
	if(cnt2 + cnt1 > 2 || cnt1 == 0) return cout << "-1\n", 0;
	for(int i = 0; i < n; i++)
		if(lst[i].size() == 1 && lst[i][0] != -1){
			// dbg(i, lst[i]);
			if(check(lst[i][0]))
				return cout << lst[i][0] << '\n', 0;
		}
	cout << "-1\n";
	return 0;
}
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

int n, e, c, q, a, b;
unordered_map <int, int> m[N];
vector <int> root[N];
vector <int> colors[N];
unordered_map <long long, int> ans;

void upd(int color, int node) {
	if(!m[color].count(node)) {
		int sz = root[color].size();
		m[color][node] = sz;
		root[color].push_back(sz);
		colors[node].push_back(color);
	}
}

int root_up(int color, int node) {
	// dbg(node);
	// dbg(root[color]);
	if(root[color][node] != node)
		root[color][node] = root_up(color, root[color][node]);
	return root[color][node];
}

int unite(int color, int a, int b) {
	root[color][root_up(color, a)] = root_up(color, b);
}

int get_ans(int a, int b) {
	if(!ans.count(min(a, b)* 1000000LL + max(a, b))) {
		int ret = 0;
		for(auto i : colors[a]) 
			if(m[i].count(b))
				ret += (root_up(i, m[i][a]) == root_up(i, m[i][b]));
		ans[min(a, b)* 1000000LL + max(a, b)] = ret;
	}
	return ans[min(a, b)* 1000000LL + max(a, b)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> e;
	// scanf("%d %d", &n, &e);
	for(int i = 1; i <= e; i++) {
		cin >> a >> b >> c;
		// scanf("%d %d %d", &a, &b, &c);
		upd(c, a);
		upd(c, b);
		// dbg(root[c]);
		unite(c, m[c][a], m[c][b]);
		// dbg_ok;
	}

	cin >> q;
	// scanf("%d ", &q);
	for(int i = 1; i <= q; i++)	{
		cin >> a >> b;
		// scanf("%d %d", &a, &b);
		if(colors[a].size() > colors[b].size()) swap(a, b);
		cout << get_ans(a, b) << '\n';
		// printf("%d\n", get_ans(a, b));
	}
}
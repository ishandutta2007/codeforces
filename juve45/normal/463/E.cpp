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
int n, p[20 * N], use[N], res[N], lvl[N], x, y, op, m, a[N];

vector <int> v[N], lst[N * 20], pr[20 * N], st;

void dfs(int node) {
	// dbg(node, a[node]);
	use[node] = 1;

	st.push_back(node);
	for(auto i : pr[a[node]])
		lst[i].push_back(st.size() - 1);

	// dbg(st);

	for(auto i : v[node])
		if(!use[i])
			dfs(i);

	lvl[node] = -1;
	res[node] = -1;

	for(auto i : pr[a[node]]) {
		lst[i].pop_back();
		// dbg(i, lst[i]);
		if(lst[i].size() && lst[i].back() > lvl[node])
			res[node] = st[lst[i].back()], lvl[node] = lst[i].back();
	}
	// dbg(node, lvl[node], res[node]);
	st.pop_back();
}

void pre() {
	for(int i = 2; i < 2000100; i++)
		if(!p[i]) {
			for(int j = 2 * i; j < 2000100; j += i)
				pr[j].push_back(i), p[j] = 1;
			pr[i].push_back(i);
		}
}

int main() {
	ios_base::sync_with_stdio(false);

	pre();

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);

	for(int i = 1; i <= m; i++) {
		cin >> op >> x;
		if(op == 1) cout << res[x] << '\n';
		else {
			cin >> y;
			a[x] = y;
			memset(use, 0, sizeof use);
			dfs(1);
		}
	}
}
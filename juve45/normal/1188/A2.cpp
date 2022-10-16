#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd ; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, a, b, c, start, leaf[N];

vector <pair<pair<long long, long long>, long long> > ans;
vector <pair<long long, long long> > v[N];

void df_leaf(long long node, long long ant = -1) {
	// dbg(node, ant);
	for(auto i : v[node])
		if(i.st != ant) {
			df_leaf(i.st, node);
			leaf[node] = leaf[i.st];
		}
	if(leaf[node] == 0) leaf[node] = node;
}

void add(long long i, long long j, long long val) {
	// dbg(i, j, val);
	ans.push_back({{i, j}, val});
}

void dfs(long long node, long long up = 0, long long ant = -1, long long aux = -1) {

	// dbg(node, up, ant, aux);

	pair<long long, long long> auxx = {-1, -1};
	if(aux == -1)
		auxx = {leaf[v[node][0].st], leaf[v[node][1].st]};

	vector <pair<long long, long long> > w;
	for(auto i : v[node]) {
		if(i.st == ant) continue;
		if(aux != -1)
			dfs(i.st, i.nd, node, aux);
		else if(leaf[i.st] == auxx.st)
			dfs(i.st, i.nd, node, auxx.nd);
		else
			dfs(i.st, i.nd, node, auxx.st);
		long long down = (leaf[i.st] != leaf[node] ? i.nd : i.nd - up);
		w.push_back({down, leaf[i.st]});
	}
	// dbg(node);
	// dbg(w);
	if(w.size() == 0) return;
	if(w.size() == 1 && w.back().st != 0) {
		cout << "NO\n";
		exit(0);
	} 
	if(w.size() == 2) {

		if(w[1].st != w[0].st && aux == -1) {
			cout << "NO\n";
			exit(0);
		}
		long long dif = w[0].st - w[1].st;
		// dbg(dif);
		// dbg(w);
		add(w[0].nd, aux, dif / 2);
		add(w[1].nd, aux, -dif / 2);
		add(w[0].nd, w[1].nd, w[0].st - dif / 2);
		return;
	}

	auto aa = w.back(); 
	w.pop_back();
	
	for(auto i : w) {
		add(i.nd, aa.nd, i.st);
		aa.st -= i.st;
	}
	if(aa.st != 0) {
		add(w[0].nd, w[1].nd, -aa.st / 2);
		add(w[0].nd, aa.nd, aa.st / 2);
		add(w[1].nd, aa.nd, aa.st / 2);
	}
}
int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	for(long long i = 1; i <= n; i++) {
		if(v[i].size() > 1)
			start = i;
	}

	if(start == 0) {
		add(1, 2, v[1][0].nd);
		cout << "YES\n" << ans << '\n';
		return 0;
	}

	df_leaf(start);
	dfs(start);
	cout << "YES\n" << ans << '\n';
}
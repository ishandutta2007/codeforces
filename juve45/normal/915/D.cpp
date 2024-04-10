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

const int N = 505;
int n, st[N], use[N], black, m, a, b;
vector <pair<int, int> > v[N];
vector <int> edges;

bool dfs(int node) {
	// dbg(node);
	use[node] = 1;
	st[node] = 1;

	for(auto i : v[node]) {
		if(i.nd == black) continue;
		// dbg(i, st[i.st]);
		if(st[i.st])
			return 0;
		else if(!use[i.st])
			if(!dfs(i.st))
				return 0;
	}
	
	st[node] = 0;
	return 1;
}

bool ok() {
	memset(use, 0, sizeof use);
	memset(st, 0, sizeof st);
	for(int i = 1; i <= n; i++)
		if(!use[i] && !dfs(i))
			return 0;
	return 1;
}

bool dfc(int node) {
	use[node] = 1;
	st[node] = 1;

	for(auto i : v[node]) {

		if(st[i.st]) {
			edges.push_back(i.nd);
			return 0;
		}
		else if(!use[i.st])
			if(!dfc(i.st)) {
				edges.push_back(i.nd);
				return 0;
			}
	}
	
	st[node] = 0;
	return 1;
}


int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back({b, i});
	}

	for(int i = 1; i <= n; i++)
		if(!use[i])
			dfc(i);

	memset(use, 0, sizeof use);
	memset(st, 0, sizeof st);
	// dbg(edges);

	for(auto i : edges) {
		black = i;
		// dbg(i);
		if(ok())
			return cout << "YES\n", 0;
	}
	if(edges.size() == 0) cout<< "YES\n";
	else cout << "NO\n";
}
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

const int N = 1001000;
int n, nrc, ans[N], p[N], a, b, use[N], m;
vector <int> v[N], c[N];

void dfs(int node) {
	use[node] = 1;
	c[nrc].push_back(node);
	for(auto i : v[node])
		if(!use[i])
			dfs(i);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
		if(!use[i])
			dfs(i), nrc++;

	for(int i = 0; i < nrc; i++) {
		vector <int> w;
		for(auto j : c[i])
			w.push_back(p[j]);
		sort(c[i].begin(), c[i].end());
		sort(w.begin(), w.end());
		for(auto j : c[i])
			ans[j] = w.back(), w.pop_back();
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}
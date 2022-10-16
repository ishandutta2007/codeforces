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

const int N = 1010;
int n, x[N], y[N], f[N], f2[N], a, b, t, start, k1, k2, res;
vector <int> v[N];

int dfs(int node, int ant = -1) {
	if(f[node]) return node;

	for(auto i : v[node])
		if(i != ant) {
			int r = dfs(i, node);
			if(r != -1) return r;
		}
	return -1;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		v[i].clear();
	memset(f, 0, sizeof f);
	memset(f2, 0, sizeof f2);

	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cin >> k1;
	for(int i = 1; i <= k1; i++) cin >> x[i], f[x[i]] = 1;
	
	cin >> k2;
	for(int i = 1; i <= k2; i++) cin >> y[i], f2[y[i]] = 1;

	cout << "B " << y[1] << endl;
	cin >> start;

	int vec = dfs(start);
	cout << "A " << vec << endl;
	cin >> res;
	if(f2[res]) cout << "C " << vec << endl;
	else cout << "C -1" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	
	while(t--) solve();
}
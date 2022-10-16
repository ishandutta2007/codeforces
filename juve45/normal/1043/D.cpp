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

const int N = 100200;
int n, k, m, a[11][N], gr[N], gre[N];
long long ans;
set <int> v[N];

int dfs(int node) {
	if(gre[node] == m && v[node].size() == 1)
		return dfs(*v[node].begin()) + 1;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];

		for(int j = 2; j <= n; j++) {
			v[a[i][j - 1]].insert(a[i][j]);
			gre[a[i][j - 1]]++;
		}
	}

	for(int i = 1; i <= n; i++)
		if(gre[i] == m && v[i].size() == 1) {
			// dbg(i, v[i]);
			gr[*v[i].begin()]++;
		}

	for(int i = 1; i <= n; i++)
		if(gr[i] == 0) {
			int k = dfs(i);
			// dbg(i, k);
			ans += 1LL * k * (k + 1) / 2;
		}

	cout << ans << '\n';
}
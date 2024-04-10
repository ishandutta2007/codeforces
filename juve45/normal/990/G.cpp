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

const int N = 200100;
int n, a[N], x, y;
long long ans[N];
vector <int> v[N], d[N];
unordered_map <int, int> m[N];

void dfs(int node, int ant = -1) {
	for(auto i : v[node]) {
		if(i == ant) continue;

		dfs(i, node);
		// dbg(m[node]);
		// dbg(m[i]);

		for(auto j : m[i])
			for(auto k : m[node])
				ans[__gcd(k.st, j.st)] += 1LL * k.nd * j.nd;
		
		for(auto j : m[i])
			m[node][__gcd(a[node], j.st)] += j.nd;
		m[i].clear();
	}
	m[node][a[node]]++;
	for(auto i : m[node])
		ans[i.st] += 1LL * i.nd;
	// 	for(auto j : m[node])
	// 		if(i == j) ans[j.st] += j.nd * (j.nd + 1) / 2;
	// 		else ans[__gcd(i.st, j.st)] += i.st * j.nd;
	// dbg(node, m[node]);
	// dbg_v(ans, 10);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for(int i = 1; i <= 200000; i++)
		for(int j = i; j <= 200000; j += i)
			d[j].push_back(i);

	dfs(1);
	// dbg_v(ans, 33);
	for(int i = 1; i <= 200000; i++)
		if(ans[i])
			cout << i << ' ' << ans[i] << '\n';

}
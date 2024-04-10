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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 200100;
long long n, gans, ans[N], sz[N], a, b;
vector <long long> v[N];

void dfs(long long node, long long ant = -1) {
	sz[node] = 1;
	for(auto i : v[node]) {
		if(i == ant) continue;
		dfs(i, node);
		ans[node] += ans[i];
		sz[node] += sz[i];
	}
	ans[node] += sz[node];
}

void dfs_ans(long long node, long long ant = -1, long long ans_up = 0) {
	long long sum_ans = 0;

	for(auto i : v[node])
		if(i != ant)
			sum_ans += ans[i];
	gans = max(ans_up + sum_ans + (node != 1 ? n : 0), gans);

	for(auto i : v[node])
		if(i != ant)
		dfs_ans(i, node, ans_up + sum_ans - ans[i] + n - sz[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	dfs_ans(1);

	cout << gans << '\n';
}
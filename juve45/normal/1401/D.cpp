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

const long long N = 100100;
const long long MOD = 1e9 + 7;
long long n, k, p, w[N], a, b, t;
vector <long long> v[N];
priority_queue <long long> pq, e;

long long dfs(long long node, long long fth = -1) {
	w[node] = 1;

	for(auto i : v[node])
		if(i != fth)
			w[node] += dfs(i, node);

	if(fth != -1)
		e.push({(w[node] * (n - w[node]))});

	return w[node];
}

long long solve() {
	cin >> n;
	for(long long i = 1; i <= n; i++)
		v[i].clear();
	assert(pq.empty());
	assert(e.empty());

	for(long long i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cin >> k;
	for(long long i = 1; i <= k; i++) {
		cin >> p;
		pq.push(p);
	}

	assert(dfs(1) == n);
	long long mul = 1;
	while(pq.size() > e.size()) {
		long long x = pq.top(); pq.pop();
		mul = mul * x % MOD;
	}
	mul = mul * pq.top() % MOD;
	pq.pop();
	pq.push(mul);

	while(pq.size() < e.size())
		pq.push(1);

	long long ans = 0;
	while(!pq.empty()) {
		ans += (1LL * pq.top() * (e.top() % MOD)) % MOD;
		ans %= MOD;
		e.pop();
		pq.pop();
	}
	return ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) cout << solve() << '\n';
}
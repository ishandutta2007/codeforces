#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 500100;
const long long MOD = 1e9 + 7;
long long n, k, root[N], val[N], m, a, b, ans, p2[N];

vector <long long> v[N];
vector <pair<long long, pair<long long, long long> > > edges;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

long long root_up(long long k) {
	if(root[k] == k)
		return k;
	return root[k] = root_up(root[k]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;

	for(long long i = 1; i <= n; i++)
		cin >> val[i];

	for(long long i = 1; i <= m; i++) {
		cin >> a >> b;
		edges.push_back({val[a] ^ val[b], {a, b}});
		v[a].push_back(b);
		v[b].push_back(a);
	}

	sort(edges.begin(), edges.end());
	

	p2[0] = 1;
	for(long long i = 1; i <= n; i++)
		root[i] = i;
	for(long long i = 1; i <= max(n, k + 1); i++)
		p2[i] = (p2[i - 1] * 2) % MOD;
	long long tot = p2[k];
	// dbg(tot);

	for(long long i = 0; i < edges.size();) {
		long long nrc = n;
		tot--;
		for(long long j = i; j < edges.size() && edges[i].st == edges[j].st; j++) {
			//bla bla, union find
			if(root_up(edges[j].nd.st) != root_up(edges[j].nd.nd)) {
				root[root[edges[j].nd.st]] = root[edges[j].nd.nd];
				nrc--;
			}
		}

		for(long long j = i; j < edges.size() && edges[i].st == edges[j].st; i++) {
			// reset union find
			root[edges[i].nd.st] = edges[i].nd.st;
			root[edges[i].nd.nd] = edges[i].nd.nd;
		}
		ans = (ans + p2[nrc]) % MOD;
	}
	dbg(tot);
	if(tot < 0) tot += MOD;
	ans += (tot * p2[n]) % MOD;

	ans %= MOD;
	cout << ans << '\n';

}
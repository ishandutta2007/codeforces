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
long long n, m, k, a, b, c, d[N], d2[N], ans;
vector <pair<long long, long long> > v[N]; 
priority_queue <pair<long long, long long> > pq;

void disjktra(long long node) {
	for(long long i = 0; i <= n; i++) d[i] = 1e9;

	d[node] = 0;
	pq.push({0, node});

	while(!pq.empty()) {
		auto p = pq.top(); pq.pop();
		int x = p.nd;

		if(x > 0 && d[x] < -p.st)
			continue;
		if(x < 0) {
			x = -x;
			if(d[x] <= -p.st) {
				ans++;
				continue;
			}
			d[x] = -p.st;
		}

		for(auto i : v[x])
			if(d[i.st] > d[x] + i.nd) {
				d[i.st] = d[x] + i.nd;
				pq.push({-d[i.st], i.st});
			}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n >> m >> k;

	for(long long i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}


	for(long long i = 1; i <= k; i++) {
		cin >> a >> c;
		pq.push({-c, -a});
	}
	disjktra(1);

	cout << ans << '\n';
}
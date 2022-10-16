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

const long long N = 100010;
long long n, k, a, b, c, start, use[N];

vector <long long> nd;
vector <pair<long long, long long> > v[N];

bool check(long long node, long long ant) {
	long long ret = 0;
	nd.push_back(node);
	for(auto i : v[node]) 
		if(i.st != ant && !use[i.st])
			ret++;

	if(ret > 1) return 0;

	for(auto i : v[node]) 
		if(i.st != ant && !use[i.st])
			return check(i.st, node);
	return 1;
}

bool dfs(long long node, long long ant = -1) {
	long long ret = 0;
	for(auto i : v[node])
		if(i.st != ant)
			ret += (long long) dfs(i.st, node);

	if(!use[node] && ret == 0) start = node;
	if(!use[node]) ret++;
	if(ret) use[node] = 0;

	return (ret != 0);
}

bool ok(long long mid) {

	memset(use, 0, sizeof use);
	vector <long long> d, gr;
	priority_queue <pair<int, int>> q;
	d.resize(n + 1);
	gr.resize(n + 1);

	for(long long i = 1; i <= n; i++) {
		gr[i] = v[i].size();
		if(gr[i] == 1) q.push({0, i});
	}

	while(!q.empty()) {
		auto x = q.top().nd; q.pop();

		for(auto i : v[x])
			if(!use[i.st]) {
				gr[i.st]--;
				d[i.st] = max(d[x] + i.nd, d[i.st]);
				
				// dbg(x, d[x], i.nd, i.st);
				if(d[x] + i.nd <= mid)
					use[x] = 1;

				if(gr[i.st] == 1 && d[i.st] <= mid)
					q.push({-d[i.st], i.st});
			}
	}

	start = -1;

	// dbg_v(use, n + 1);

	for(long long i = 1; i <= n; i++)
		if(!use[i]) {
			dfs(i);
			break;
		}
	if(start == -1) return 1;

	nd.clear();
	if(check(start, -1) && nd.size() <= k) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(long long i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	// dbg(ok(16));
	// return 0;

	long long l =0, r = 2e9;
	while(l != r) {
		// dbg(l, r);
		long long mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}
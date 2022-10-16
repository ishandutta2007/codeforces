#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 300100;
long long n, a, x, y, t[N], s[N], sums, sumt, tt[N], p[N];
vector <pair<long long, pair<long long, long long > > > moves;
set <pair<long long, long long> > v[2];

void close(long long x, long long y) {
	// dbg(x, y);
	long long d = min(t[x] - s[x], s[y] - t[y]);
	s[x] += d;
	s[y] -= d;

	moves.push_back({x, {y, d}});
}

bool cmp(int a, int b) {
	return s[a] < s[b];
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;


	for(long long i = 1; i <= n; i++) {
		cin >> s[i];
		sums += s[i];
	}

	for(long long i = 1; i <= n; i++) {
		cin >> tt[i];
		sumt += tt[i];
	}

	for(int i = 1; i <= n; i++) p[i] = i;
	sort(p + 1,  p + n + 1, cmp);
	sort(tt + 1, tt + n + 1);
	for(int i = 1; i <= n; i++) t[p[i]] = tt[i];

	// dbg_v(s, n + 1);
	// dbg_v(p, n + 1);
	// dbg_v(t, n + 1);


	// if(sums != sumt) {
	// 	cout << "NO\n";
	// 	return 0;
	// }


	for(long long i = 1; i <= n; i++) {
		if(s[i] == t[i]) continue;
		if(s[i] < t[i]) v[0].insert({s[i], i});
		else v[1].insert({s[i], i});
	}

	while(!v[0].empty() && !v[1].empty()) {
		long long x = v[0].begin()->nd;
		auto p = v[1].lower_bound({s[x], 1e9});
		if(p == v[1].end()) {
			cout << "NO\n";
			return 0;
		}
		long long y = p->nd;

		close(x, y);

		v[1].erase(p);
		v[0].erase(v[0].begin());
		if(s[y] != t[y]) v[1].insert({s[y], y});
		if(s[x] != t[x]) v[0].insert({s[x], x});
	}
	if(!v[0].empty() || !v[1].empty()) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << moves;

}
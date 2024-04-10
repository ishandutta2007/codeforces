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

const long long N = 300100;
long long n, m, k, a[N], b[N], c[N], x, y, mx[N], use[N], val[N], low[N];
vector <long long> v[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for(long long i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

	for(long long i = 1; i <= m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
	}

	val[0] = k;
	for(long long i = 1; i <= n; i++) {
		if(val[i - 1] >= a[i]) 
			val[i] = val[i - 1] + b[i];
		else return cout << "-1\n", 0;
	}

	for(long long i = n; i >= 0; i--) {
		low[i] = max(low[i + 1] - b[i], a[i]);
	}

	for(long long i = 1; i <= n; i++)
		mx[i] = max(mx[i - 1], a[i]);

	set <pair<long long, long long> > s;
	long long ans = 0, spare = 0;

	// dbg_v(val, n + 1);
	// dbg_v(low, n + 1);
	
	long long old_spare = val[n];

	for(long long i = n; i >= 1; i--) {
	
		if(!use[i])
			s.insert({c[i], i}), use[i] = 1;

		for(auto j : v[i])
			if(!use[j])
				s.insert({c[j], j}), use[j] = 1;

		long long new_spare = (i == 0 ? k : val[i - 1]) - low[i];

		// dbg(i, new_spare, old_spare, s);


		if(new_spare < old_spare) {
			while (old_spare > new_spare && !s.empty()) {
				old_spare--;
				ans += s.rbegin()->st;
				auto p = *s.rbegin();
				// dbg(p);
				s.erase(p);
			}
		}

		while(s.size() > new_spare) s.erase(s.begin());
		old_spare = new_spare;
	}

	while (old_spare && !s.empty()) {
		old_spare--;
		ans += s.rbegin()->st;
		auto p = *s.rbegin();
		// dbg(p);
		s.erase(p);
	}

	cout << ans << '\n';
	return 0;
}
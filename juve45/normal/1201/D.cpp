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
long long n, m, k, q, l[N], r[N], x, y, ans = 1e16, maxy = 0;

set <long long> s;


long long dist(long long in, long long out, long long l, long long r) {
	// dbg(in, out, l, r);
	long long ret = (r - l) + min(abs(in - l) + abs(r - out), abs(in - r) + abs(l - out));
	// dbg(ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> q;
	
	memset(l, 0x3f, sizeof l);
	memset(r, 0, sizeof r);

	for(long long i = 1; i <= k; i++)  {
		cin >> x >> y;
		l[x] = min(l[x], y);
		r[x] = max(r[x], y);
		maxy = max(x, maxy);
	}
	x = 1, y = 1;
	l[x] = min(l[x], y);
	r[x] = max(r[x], y);

	for(long long i = 1; i <= q; i++)
		cin >> x, s.insert(x);

	set <pair<long long, long long> > in, new_in;
	set <long long> exit;
	in.insert({1, 0});

	for(long long i = 1; i <= n; i++) {
		if(!r[i])
			continue;
		if(i == maxy) {
			s.insert(l[i]);
			s.insert(r[i]);
		}
		
		auto itr = s.lower_bound(r[i]);
		if(itr != s.end()) exit.insert(*itr);
		if(itr != s.begin()) itr = prev(itr);
		if(itr != s.end()) exit.insert(*itr);

		auto itl = s.lower_bound(l[i]);
		if(itl != s.end()) exit.insert(*itl);
		if(itl != s.begin()) itl = prev(itl);
		if(itl != s.end()) exit.insert(*itl);

			for(auto j : exit)  {
				long long cost = 1e16;
				for(auto ii : in) {
					if(cost > dist(ii.st, j, l[i], r[i]) + ii.nd)
						cost = dist(ii.st, j, l[i], r[i]) + ii.nd;
					// dbg(j, ii, cost);
				}
				new_in.insert({j, cost});
			}
		in = new_in;
		exit.clear();
		new_in.clear();
		// dbg(in);
	}
	dbg(maxy);
	for(auto i : in)
		ans = min(ans, i.nd);
	cout << ans + maxy - 1 << '\n';
}
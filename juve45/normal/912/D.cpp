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

// const long long N = ;
long long n, m, r, k, ans;

long long nr(long long x, long long n) {
	if(x + r - 1 > n) return 0;
	if(x + r - 1 == n) return n - 2 * (x - 1);
	if(x == r) return n - 2 * (r - 1);
	return 2;
}

long long cnt(long long x, long long y, long long n, long long m) {
	return nr(x, n) * nr(y, m);
}

long long cnt(long long x, long long y) {
	if(x != y)
		return cnt(x, y, n, m) + cnt(x, y, m, n);
	return cnt(x, y, n, m);
}
priority_queue<pair<long long, pair<long long, long long> > > pq;
set<pair<long long, long long> > use;

void add(long long x, long long y) {
	if(x > y) swap(x, y);
	if(use.count({x, y})) return;
	use.insert({x, y});
	pq.push({x * y, {x, y}});
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> r >> k;
	// dbg(nr(3, 7));
	// dbg(nr(3, 5));
	// dbg(cnt(3, 3));

	long long x = min(r, n - r + 1);
	long long y = min(r, m - r + 1);
	if(x > y) swap(x, y);
	use.insert({x, y});
	pq.push({x * y, {x, y}});

	while(k) {
		auto p = pq.top().nd;
		pq.pop();
		long long rem = min(k, cnt(p.st, p.nd));
		k -= rem;
		// dbg(rem, p);
		ans += rem * (p.st * p.nd);
		add(p.st - 1, p.nd);
		add(p.st, p.nd - 1);
	}
	// dbg(nr(4, 7));
	// dbg(nr(2, 5));
	// dbg(ans);
	// dbg((n - r + 1) * (m - r + 1));
	cout <<fixed << setprecision(16) << 1. * ans / ((n - r + 1) * (m - r + 1));
}
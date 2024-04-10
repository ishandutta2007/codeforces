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
long long n, pos[N], f[N], ans, a[N];

priority_queue <pair<long long, long long> > pq;
set <long long> s;

long long get(long long l, long long r, long long val, long long x, long long ll, long long rr) {
	long long ret = 0;
	// dbg(l, r, x);
	for(long long i = l; i <= r; i++)
		f[a[i]] = 1;
	
	for(long long i = l; i <= r; i++) {
		assert(val > a[i]);
		if(!f[val - a[i]] && ll < pos[val - a[i]] && pos[val - a[i]] < rr)
			ret++;
	}

	for(long long i = l; i <= r; i++)
		f[a[i]] = 0;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
		pq.push({a[i], i});
	}
	s.insert(0);
	s.insert(n + 1);

	while(!pq.empty()) {
		long long x = pq.top().nd; pq.pop();
		auto it = s.upper_bound(x);
		long long r = *it;
		auto it2 = prev(it);
		long long l = *it2;
		// dbg(x, l, r);

		if(r - x < x - l) ans += get(x + 1, r - 1, a[x], x, l, r);
		else ans += get(l + 1, x - 1, a[x], x, l, r);
		s.insert(x);
		// dbg(x, ans);
	}
	cout << ans << '\n';
}
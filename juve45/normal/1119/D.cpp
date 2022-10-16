#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, deque <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, x[N], q, l, r, ans[N], mn = 1e18, w[N];
set <long long> s;
map <long long, long long> m;
deque <pair<long long, long long> > v;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> x[i];
		mn = min(x[i], mn);
	}

	sort(x + 1, x + n + 1);

	x[1] -= mn;
	for(long long i = 2; i <= n; i++) {
		x[i] -= mn;
		m[x[i] - x[i - 1]] ++;
	}

	cin >> q;
	for(long long i = 1; i <= q; i++) {
		cin >> l >> r;
		// w[i] = r - l;
		v.push_back({r - l, i});
	}

	sort(v.begin(), v.end());

	long long last = 0;
	long long off = 0;
	long long curr = n;

	// dbg(m);
	// dbg(v);

	for(auto i : m) {

		// dbg(i, curr, last, off);
		while(v[0].st < i.st) {
			// dbg(v[0]);
			ans[v[0].nd] = off + (v[0].st - last + 1) * curr;
			v.pop_front();
		}
		
		off += (i.st - last) * curr;
		last = i.st;
		curr -= i.nd;
	}

	// dbg(off, last, curr);
	// dbg_ok;

	while(!v.empty()) {
		// dbg(v[0]);
		ans[v[0].nd] = off + curr * (v[0].st - last + 1);
		v.pop_front();
	}

	for(long long i = 1; i <= q; i++) cout << ans[i] << ' ';
}
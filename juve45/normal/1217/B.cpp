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

const long long N = 123;
long long n, t, d[123], h[123], x;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;
	for(long long i= 1; i <= t; i++) {
		cin >> n >> x;

		long long maxd = 0, maxdelta = -1e9;
		for(long long i= 1; i <= n; i++) {
			cin >> d[i] >> h[i];
			long long delta = d[i] - h[i];
			maxdelta = max(delta, maxdelta);
			maxd = max(d[i], maxd);
		}

		if(maxdelta <= 0 && maxd < x) {
			cout << "-1\n";
			continue;
		}

		long long req = (x - maxd);
		dbg(req);
		if(req <= 0) {
			cout << "1\n"; 
			continue;
		}
		// dbg(req, maxdelta);
		cout << (req + maxdelta - 1)/ maxdelta + 1 << '\n';
	}
}
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
long long n, a[N], ans, k;

map <long long, long long> m[11];

long long nrc(long long k) {
	long long ret = 0;
	while(k) {
		ret++;
		k /= 10;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		m[nrc(a[i])][a[i] % k]++;
	}

	// dbg(m[1]);
	// dbg(m[2]);

	for(long long i = 1; i <= n; i++) {
		long long mul = 10;
		// dbg(a[i]);
		for(long long nr = 1; nr <= 10; nr++) {
			long long nrr = ((unsigned long long) a[i] * mul) % k;
			long long req = (k - nrr) % k;
			ans += m[nr][req];
			// dbg(nr, req);
			if(req == a[i] % k && nr == nrc(a[i]))
				ans--;

			mul *= 10;
		}
		// dbg(ans);
	}
	cout << ans << '\n';
}
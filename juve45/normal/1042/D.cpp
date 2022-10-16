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

const long long N = 1e18;
long long n, a, s, t, ans;
map <long long, long long> aib;

long long lsb(long long k) {
	return k & (-k);
}

void add(long long pos, long long val){
	pos += N;
	for(;pos < 2 * N; pos += lsb(pos))
		aib[pos] += val;
}

long long que(long long pos) {
	long long ret = 0;
	pos += N;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	// add(5,1);
	// add(4, 1);
	// dbg(que(7));


	cin >> n >> t;
	add(0, 1);
	for(long long i = 1; i <= n; i++) {
		cin >> a;
		s += a;
		ans +=  i- que(s - t); // > s - t
		// dbg(s - t);
		// dbg(i, s);
		add(s, 1);
	}
	cout << ans << '\n';
}
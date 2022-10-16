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

const long long N = 100100;
const long long MOD = 1e9 + 7;
long long n, a[N], s, k;
map <long long, long long> m;

long long powMod(long long base, long long exp) {
	if(exp == 0) return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++) cin >> a[i], s += a[i];
	// if(n == 1) return cout << powMod(k, s), 0;
	// long long e = *max_element(a + 1, a + n + 1);

	for(int i = 1; i <= n; i++)
		m[s - a[i]]++;

	while(m.begin()->nd % k == 0) {
		pair<long long, long long> p = *m.begin();
		p.st++;
		p.nd /= k;
		m.erase(m.begin());
		m[p.st] += p.nd;
	}

	long long off = min(m.begin()->st, s);

	// for(long long i = 1; i <= n; i++)
	// 	m[s - a[i] - off]++;

	// dbg(m);
	// long long i = 0;
	// while(m.count(i) && m[i] % k == 0) {
	// 	m[i + 1] += m[i] / k;
	// 	i++;
	// 	off++;
	// 	dbg(i, off);
	// }

	cout << powMod(k, off);

	// auto it = m.end();
	// // it--;
	// do {
	// 	it--;

	// } while (it != m.begin());
	// cout << powMod(x, s - e);
}
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
//
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

long long n, k, m, a, b, l, r, ans;

const long long MOD = 1e9 + 7;

long long s(long long start, long long cate) {
	start %= MOD;
	cate %= MOD;
	long long res = (start * cate) % MOD + ((cate - 1) * cate) % MOD;
	return res;
}

long long f(long long nr) {

	long long lg = 1, last = 0, ans = 0;
	long long par = 0;
	long long last_impar = 1;
	long long last_par = 2;

	while(last + 3 * lg <= nr) {
		ans += s(last_impar, lg);
		ans %= MOD;
		last_impar += 2 * lg;

		ans += s(last_par, 2 * lg);
		ans %= MOD;
		last_par += 4 * lg;
		last += 3 * lg;
		// lg = 4 * lg;
		lg *= 4;
		// dbg(last);
	}
	// dbg(last_impar);
	// dbg(last_par);
	// dbg(lg);
	lg = min(lg, nr - last);
	ans += s(last_impar, lg);
	ans %= MOD;
	last_impar += 2 * lg;
	last += lg;

	lg *= 2;
	lg = min(lg, nr - last);
	ans += s(last_par, lg);
	ans %= MOD;
	last_par += 2 * lg;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> l >> r;
	// dbg(s(2, 4));
	long long aa = f(r);
	long long bb = f(l - 1);
	// dbg(f(r));
	// dbg(f(l));
	dbg(aa);
	dbg(bb);
	cout << (aa - bb + MOD) % MOD << '\n';
}
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

const long long N = 600100;
long long n, lim, cnt[N];

long long cntt(long long sum) {
	if(sum < 0) return 0;
	return cnt[sum];
}

long long a, b, c;

long long comb(long long n, long long k) {
	long long ans = 1;
	for(long long i = 0; i < k; i++)
		ans *= (n - i);
	for(long long i = 1; i <= k; i++)
		ans /= i;
	return ans;
}

long long res(long long a, long long b, long long c) {
	long long ret = 0;
	// dbg(a, b, c);
	for(long long i = 0; i <= lim; i++) {
		// a + lim >= b + c + x
		// x <= a + lim - b - c
		long long mx = min(a + i - b - c, lim - i);
		if(mx < 0) continue;
		ret += (mx + 1) * (mx + 2) / 2;
		// dbg(i, mx, ret);
		// dbg(ret);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c >> lim;

	long long ans = 0;
	for(long long i = 0; i <= lim; i++) 
		ans += comb(i + 2, 2);
	// dbg(ans);


	for(long long i = 0; i <= lim; i++)
		cnt[i] = i + 1;
	for(long long i = lim + 1; i <= 2 * lim; i++)
		cnt[i] = cnt[i - 1] - 1;
	for(long long i = 1; i <= 2 * lim; i++)
		cnt[i] += cnt[i - 1];
	// dbg_v(cnt, 2 * lim + 1);

	ans -= res(a, b, c);
	ans -= res(b, a, c);
	ans -= res(c, b, a);
	cout << ans << '\n';
	return 0;

	// for()
}
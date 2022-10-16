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

const long long N = 1005;
long long n, m, w[N][N], sl[N], sc[N], s[N][N];
long long a, b, c ,d, q;


long long value(long long x, long long y) {
	x--;
	y--;
	long long val = __builtin_popcount(x) + __builtin_popcount(y);
	return 1 - val % 2;
}

long long normal(long long k) {
	if(k % 2 == 0)
		return k / 2;
	else 
		return k / 2 + value(0, k);
}


long long cnt(long long x, long long y) {
	// center
	long long xx = x / n;
	long long yy = y / m;

	long long nlin = normal(xx);
	long long alin = xx - nlin;

	long long ncol = normal(yy);
	long long acol = yy - normal(yy);

	long long tot_norm = nlin * ncol + alin * acol;
	long long tot_an = nlin * acol + alin * ncol;

	long long ans = 0;
	ans += tot_norm * s[n][m];
	ans += tot_an * (n * m - s[n][m]);

	if(x % n != 0) {
		if(value(xx + 1, 1) == 0) 
			swap(ncol, acol);
		ans += ncol * sl[x % n];
		ans += acol * ((x % n) * m - sl[x % n]);
	}

	if(y % m != 0) {
		if(value(1, yy + 1) == 0) 
			swap(nlin, alin);
		ans += nlin * sc[y % m];
		ans += alin * ((y % m) * n - sc[y % m]);
	}

	if(x % n != 0 && y % m != 0) {
		if(value(xx + 1, yy + 1) == 1)
			ans += s[x % n][y % m];
		else 
			ans += (x % n) * (y % m) - s[x % n][y % m];
	}

	return ans;
}
string ss;


long long que(long long x1, long long y1, long long x2, long long y2) {
	y1--, x1--;
	return cnt(x2, y2) - cnt(x2, y1) - cnt(x1, y2) + cnt(x1, y1);
}

int main() {
	ios_base::sync_with_stdio(false);
	// dbg(value(0, 4));

	cin >> n >> m >> q;
	for(long long i = 1; i <= n; i++) {
		cin >> ss;
		for(long long j = 1; j <= m; j++)
			w[i][j] = (ss[j - 1] == '1');
	}

	// dbg_v(w[1], 3);
	// dbg_v(w[2], 3);

	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= m; j++)
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + w[i][j];

	// dbg(s[n][m]);

	for(long long i = 1; i <= n; i++)
		sl[i] = s[i][m];	

	for(long long i = 1; i <= m; i++)
		sc[i] = s[n][i];

	for(long long i = 1; i <= q; i++) {
		cin >> a >> b>> c >> d;
		cout << que(a, b, c, d) << '\n';
	}


	// cout << cnt(4, 5) << '\n';
	// cout << cnt(7, 5) << '\n';
	// cout << cnt(4, 8) << '\n';
	// cout << cnt(7, 8) << '\n';
	// cout << cnt(6, 7);
	// cout << cnt(11, 11);
}
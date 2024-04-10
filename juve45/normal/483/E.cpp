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

const long long N = 55;
long long n, m, dif[N][N], d[1LL << 21];
long double p[55], ans;
string s[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 0; i < n; i++)
		cin >> s[i];

	m = s[1].size();

	p[0] = 1;
	for(long long i = 1; i <= m; i++)
		p[i] = (1. * i / (m - i + 1)) * p[i - 1];
	// dbg_v(p, m);

	for(long long i = 0; i < n; i++)
		for(long long j = i + 1; j < n; j++) {
			for(long long k = 0; k < m; k++)
				if(s[i][k] == s[j][k]) {
					dif[i][j] += (1LL << k);
				}
			d[dif[i][j]] |= (1LL << i);
			d[dif[i][j]] |= (1LL << j);
		}

	// for(long long i = 0; i < (1LL << m); i++)

	for(long long i = (1LL << m) - 1; i >= 0; i--) {
		for(long long j = 0; j < m; j++)
			if(i & (1LL << j))
				d[i ^ (1LL << j)] |= d[i];
	}

	for(long long i = 0; i < (1LL << m); i++) {

		for(long long j = 0; j < m; j++)
			if((i & (1LL << j)) == 0) {
				if(d[i] < d[i | (1LL << j)]) continue;
				long long moves = (__builtin_popcountll(i) + 1);
				// dbg(m, moves);
				long double prob = p[__builtin_popcountll(i)] * (1. / (m - moves + 1));
				long long guess = __builtin_popcountll(d[i] ^ d[i | (1LL << j)]);
				// dbg(i, j, d[i], d[i | (1LL << j)], prob, guess, moves);
				ans += prob * moves *  guess / n;
				// dbg(ans);
			}
	}
	cout << fixed << setprecision(10) << ans << '\n';
}
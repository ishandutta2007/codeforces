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

const long long N = 400100;
long long n, q, up[22][N], sum[22][N], op, x, y, w[N];

long long get(long long node, long long val) {
	// dbg(node, val);
	for(long long i = 19; i >= 0; i--) 
		if(w[up[i][node]] < val)
			node = up[i][node];
	// dbg(node);
	if(w[node] < val) node = up[0][node];
	return node;
	// while(x != 0 && w[x] < w[n]) x = up[0][x];
}

int main() {
	ios_base::sync_with_stdio(false);


	cin >> q;

	w[0] = 2e18;
	long long n = 1;
	long long last = 0;
	// memset(sum, 0x3f, sizeof sum);

	for(long long ii = 1; ii <= q; ii++) {
		cin >> op;
		cin >> x>> y;
		x ^= last;
		y ^= last;
		if(op == 1) {
			w[++n] = y;
			x = get(x, w[n]);
			up[0][n] = x;
			sum[0][n] = w[n];
			// dbg(n);
			// dbg(up[0][n], sum[0][n]);
			for(long long i = 1; i < 20; i++) {
				up[i][n] = up[i - 1][up[i - 1][n]];
				sum[i][n] = sum[i - 1][up[i - 1][n]] + sum[i - 1][n];
				// dbg(i, up[i][n], sum[i][n]);
			}
		} else {
			long long ans = 0;
			// dbg(x, y);
			for(long long i = 19; i >= 0; i--) {
				if(up[i][x] && sum[i][x] <= y) {
					// dbg(i, up[i][x], sum[i][x]);
					y -= sum[i][x];
					x = up[i][x];
					ans += (1 << i);
				}
			}
			// dbg(x, y);
			if(up[0][x] == 0 && w[x] <= y) ans++;
			cout << ans << '\n';
			last = ans;
		}
	}

}
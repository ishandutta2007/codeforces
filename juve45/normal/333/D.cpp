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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 1003;

int n, m, a[N][N];

	bitset <N> b[N];
bool ok(int val) {
	// dbg(val);

	for(int i = 1; i <= n; i++) {
		b[i].reset();
		for(int j = 1; j <= m; j++)
			if(a[i][j] >= val)
				b[i][j] = 1;

		for(int j = 1; j < i; j++) {
			bitset<N> t = (b[i] & b[j]);
			int pos = t._Find_first();
			if(pos < t.size() && t._Find_next(pos) < t.size())
				return 1;
		}
	}

	// for(int i = 1; i <= n; i++)
	return 0;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin >> n >> m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
			// cin >> a[i][j];

	int l = 0, r = 1e9;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(ok(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	// cout << l << '\n';
}
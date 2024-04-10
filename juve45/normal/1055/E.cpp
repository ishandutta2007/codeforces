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

const int N = 1555;
int n, a[N], l[N], r[N], nr[N], m, s, k, dp[N][N], dp2[N][N], b[N], ant[N];

vector <pair<int, int>> seg;

bool ok(int lim) {
	memset(dp, 0, sizeof dp);
	memset(dp2, 0, sizeof dp2);

	for(int i = 1; i <= n; i++)
		b[i] = (a[i] <= lim);

	for(int i = 1; i <= n; i++)
		b[i] += b[i - 1];
	// dbg_v(b, n + 1);

	// int last = 0;
	for(int i = 0; i < s; i++) {

		for(int j = 1; j <= min(i + 1, m); j++) {
			
			int prev = 0;
			if(i > 0) prev = r[i - 1];
			
			for(int k = prev + 1; k <= r[i]; k++)
				dp2[j][k] = max(dp2[j][k], dp2[j][k - 1]);
			
			dp[i][j] = dp2[j - 1][l[i] - 1] + b[r[i]] - b[l[i] - 1];
			
			if(ant[i] != -1)
				dp[i][j] = max(dp[i][j], dp[ant[i]][j - 1] + b[r[i]] - b[r[ant[i]]]);
		

			dp2[j][r[i]] = max(dp[i][j], dp2[j][r[i]]);
			
			if(j <= m && dp[i][j] >= k) {
				// dbg(i, j);
				return 1;
			}
		}

	}
	return 0;
	// return dp[]
}

bool inter(pair<int, int> a, pair<int, int> b) {
	if(max(a.st, b.st) > min(a.nd, b.nd))
		return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> s >> m >> k;

	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= s; i++) {
		cin >> l[i] >> r[i];
		seg.push_back({r[i], l[i]});
	}

	sort(seg.begin(), seg.end());


	for(auto &i : seg)
		swap(i.st, i.nd);

	for(int i = 0; i < s; i++)
		l[i] = seg[i].st, r[i] = seg[i].nd;

	// dbg(seg);

	for(int i = 0; i < seg.size(); i++) {
		ant[i] = -1;
		int lim = seg[i].st;

		for(int j = 0; j < i; j++)
			if(inter(seg[i], seg[j]))
				if(seg[j].st < lim) {
					lim = seg[j].st;
					ant[i] = j;
				}
	}
	// dbg_v(ant, seg.size());


	// dbg(ok(14));

	int l = 1, r = 1e9 + 100;
	while(l != r) {
		int mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	if(l > 1e9) l = -1;
	cout << l << '\n';
}
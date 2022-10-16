#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const int N = 105;
int n, k, m, ant[N][10 * N];
double c, t, dp[N][10*N];

struct asd {
	int a, p;

	bool operator<(asd & aa) const {
		return a < aa.a;
	}
} v[N];


double f(double init, double s) {
	return init/(0.9 + 0.9 * s * c) + s;
}

double ts(double l, double r, double tt) {
	for(int i = 0; i <= 50; i++) {
		double mid1 = (l + l + r) / 3;
		double mid2 = (l + r + r) / 3;
		if(f(tt, mid1) < f(tt, mid2)) r = mid2;
		else l = mid1;
	}
	return l;
}

void solve() {
	cin >> n;
	cin >> c >> t;

	for(int i = 1; i <= n; i++) 
		cin >> v[i].a >> v[i].p;

	sort(v + 1,  v +n + 1);

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= 10 * n; j++)
			dp[i][j] = 1e16;
	dp[0][0] = 0;

	double cc = 1. / 0.9;

	for(int i = 1; i <= n; i++)
		for(int c = n; c > 0; c--)
			for(int j = 10 * n; j > 0; j--) {
				if(j >= v[i].p && dp[c][j] > v[i].a + cc * dp[c - 1][j - v[i].p]) {
					dp[c][j] = v[i].a + cc * dp[c - 1][j - v[i].p];
					ant[c][j] = i;
				}
			}

	int ans = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 10 * n; j++) {
			if(dp[i][j] < 9e15) {

				double train = ts(0, t, dp[i][j]);
				// dbg(train);
				// dbg(f(dp[i][j], train));
				if(f(dp[i][j], train) + 10. * i <= t)
					ans = max(ans, j);	
			}
		}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--) solve();
}
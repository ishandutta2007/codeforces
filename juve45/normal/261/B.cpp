#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 55;
long long n, k, dp[N][N][N], a[N], p, sum;
long double ans;
long double f[N];

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

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	cin >> p;

	if(sum <= p) return cout << n << '\n', 0;

	cout << fixed << setprecision(10);

	f[0] = 1;
	for(int i = 1; i <= 50; i++)
		f[i] = f[i - 1] * i;

	for(int e = 1; e <= n; e++) {
		//ignor elementul e, ca sa il adaug mereu la final
		
		memset(dp, 0, sizeof dp);
		for(int i = 0; i <= 50; i++)
			dp[i][0][0] = 1;

		for(int i = 1; i <= n; i++)
			for(int k = 1; k <= i; k++)
				for(int j = 1; j <= p; j++) {

					dp[i][k][j] = dp[i - 1][k][j];

					if(j - a[i] >= 0 && i != e)
						dp[i][k][j] += dp[i - 1][k - 1][j - a[i]];
				}

		for(int i = 1; i <= p; i++)
			for(int j = 1; j < n; j++)
				if(i + a[e] > p) {
					long double fact = ((long double) f[j] * f[n - j - 1] / f[n]);
					dbg(fact);
					dbg(dp[n][j][i]);
					ans += fact * j * dp[n][j][i];
				}
		dbg(e);
		dbg(ans);
	}
	cout << ans << '\n';
}
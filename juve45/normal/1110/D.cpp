#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T> ostream& print(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return print(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int INF = 1e9;
const int N = 1001000;
int n, k, m, dp[N][4][7], f[N], a[N], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}

	for(int i = 0; i <= m; i++)
		for(int j = 0 ;j < 3; j++)
			for(int k = 0 ;k < 5; k++)
			dp[i][j][k] = -INF;

	dp[0][0][0] = 0;
	dp[0][1][0] = 0;
	dp[0][2][0] = 0;
	// dp[0][0][0] = 0;

	// dbg_v(f, m + 1);

	for(int i = 1; i <= m; i++){
		for(int l1 = 0; l1 <= 2; l1++) 
			for(int l2 = 0; l2 <= 4; l2++) {

				// if(i == 1) dbg(l1), dbg(l2);
				if(f[i - 1] < l1 || f[i] < l2) continue; 
				// if(i == 1) dbg_ok;
				for(int i1 = 0; i1 <= 2; i1++)
					for(int i2 = l1; i2 <= 4; i2++) 
						if (f[i] - l2 - min(i2 - l1, i1) >= 0) {
							int nr = min(i2 - l1, i1);
							dp[i][l1][l2] = max(dp[i][l1][l2], dp[i - 1][i1][i2] + nr + (f[i] - l2 - nr) / 3);
						}

		}
		// cout << "i: " << i << '\n';
		// for(int ii = 0; ii < 3; ii++) {
		// 	for(int jj = 0; jj < 5; jj++)
		// 		cout << dp[i][ii][jj] << ' ';
		// 	cout << '\n';
		// }
		// cout << '\n';		
	}

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 5; j++)
			ans = max(ans, dp[m][i][j]);
	cout << ans << '\n';
}
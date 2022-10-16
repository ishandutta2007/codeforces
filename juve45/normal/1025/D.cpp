#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define LEFT 0 
#define RIGHT 1 

using namespace std;

const int N = 707;
int n, k, a[N], b[N][N], dp[N][N][4];

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
		cin >> a[i];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(__gcd(a[i], a[j]) > 1)
				b[i][j] = 1;

	for(int lg = 1; lg <= n; lg++) {
		for(int i = 1; i + lg - 1 <= n; i++) {
			int j = i + lg - 1;
			if(i == j) {
				if(b[i - 1][i])
					dp[i][i][LEFT] = 1;
				if(b[i + 1][i])
					dp[i][i][RIGHT] = 1;
			} else {
				for(int k = i; k <= j; k++) {
					if(b[i-1][k] && (i == k || dp[i][k-1][RIGHT]) && (j == k || dp[k+1][j][LEFT]))
						dp[i][j][LEFT] = 1;
					if(b[k][j+1] && (i == k || dp[i][k-1][RIGHT]) && (j == k || dp[k+1][j][LEFT]))
						dp[i][j][RIGHT] = 1;	
				}
			}
		}
	}

	for(int k = 1; k<= n; k++)
		if((1 == k || dp[1][k-1][1]) && (n == k || dp[k+1][n][0]))
			return cout << "Yes\n", 0;
	cout << "No\n";

}
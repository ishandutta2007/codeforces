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

const int N = 200100;
const int MOD = 1e9 + 7;
int n, k, m, dp[N][3], f[3], l, r;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> l >> r;
	while(l % 3 != 0 && l <= r)
		f[l % 3]++, l++;
	while(r % 3 != 2 && l <= r)
		f[r % 3]++, r--;

	if(l <= r) {
		if(l == r) f[l % 3]++;
		else {
			f[0] += (r -l + 1) / 3;
			f[1] += (r -l + 1) / 3;
			f[2] += (r -l + 1) / 3;
		}
	}

	dbg_v(f, 3);

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) 
		for(int j = 0; j < 3; j++) 
			for(int k = 0; k < 3; k++) {
				dp[i][(j + k) % 3] += (1LL * dp[i - 1][k] * f[j]) % MOD;
				dp[i][(j + k) % 3] %= MOD;
			}
	
	cout << dp[n][0] << '\n';
}
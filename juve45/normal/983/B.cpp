#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 5050
#define NMAX 
#define MMAX 

using namespace std;

int n, k, mat[DMAX][DMAX], dp[DMAX][DMAX], a[DMAX], l, r, q;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


int eval(int i, int j) {
	if(i == j) return a[i];
	int sz = j - i + 1;
	if(sz == 2) return a[i] ^ a[j];
	if(sz % 2 == 0) return a[i] ^ a[i + 1] ^ a[j] ^ a[j - 1];
	return a[i] ^ a[j];
}

void pre() {

	for(int i = 1; i <= n; i++)
		mat[i][i] = a[i];

	for(int i = n; i > 0; i--)
		for(int j = i + 1; j <= n; j++)
			mat[i][j] = mat[i][j - 1] ^ mat[i + 1][j];

	for(int i = n; i > 0; i--)
		for(int j = i; j <= n; j++)
			dp[i][j] = max({dp[i + 1][j], dp[i][j - 1], mat[i][j]});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];

	pre();
	cin >> q;
	for(int i = 1; i <= q; i++) {
		cin >> l >> r;
		cout << dp[l][r] << '\n';
	}
}
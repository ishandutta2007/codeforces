#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 2010
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x[DMAX], y[DMAX], f[4][DMAX], a[DMAX];
string s;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) f[1][i] = f[1][i - 1] + (a[i] == 1);
	for(int i = 1; i <= n; i++) f[2][i] = f[2][i - 1] + (a[i] == 2);


	for(int i = 1; i <= n; i++) {
		x[i] = 0;
		for(int j = 1; j <= i; j++)
			x[i] = max(x[i], f[1][j] + f[2][i] - f[2][j - 1]);
	}

	for(int i = n; i > 0; i--){
		y[i] = 0;
		for(int j = n; j >= i; j--) {
			y[i] = max(y[i], f[2][n] - f[2][j - 1] + f[1][j] - f[1][i - 1]);
		}
	}

	x[0] = 0;
	y[n + 1] = 0;
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		ans = max(x[i] + y[i + 1], ans);
	}
	cout << ans << '\n';
}
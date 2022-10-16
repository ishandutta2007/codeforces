#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n';}
#define all(v) v.begin(), v.end()
#define INF 2000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 2010
#define MMAX 210
#define P 239017

int m, n;
char s1[NMAX][MMAX], s2[MMAX][NMAX];
int phi[NMAX];
ull a[NMAX], b[MMAX][NMAX], c[NMAX], deg[NMAX];

ull getHash(int i, int len) {
	return c[i + len] - c[i] * deg[len];
}

int kmp(int col) {
	// check if col occurs in a
	
	int i, k;
	
	for(k = 0, i = 1; i <= n; ++i) {
		while(k && a[i] != b[k + 1][col]) k = phi[k];
		if(a[i] == b[k + 1][col]) ++k;
		
		if(k == m) return i - m + 1;
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int i, j, k, ret;
	
	cin >> n >> m;
	for(i = 0; i < n; ++i) cin >> s1[i];
	for(i = 0; i < m; ++i) cin >> s2[i];
	
	for(i = 0; i < n; ++i) {
		for(j = 0; j < m; ++j) {
			a[i + 1] = a[i + 1] * P + s1[i][j];
		}
	}
	
	for(deg[0] = 1, i = 1; i < NMAX; ++i)
		deg[i] = deg[i - 1] * P;
	
	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			c[j + 1] = c[j] * P + s2[i][j];
		}
		
		for(j = 0; j + m - 1 < n; ++j)
			b[i + 1][j + 1] = getHash(j, m);
	}
	
	for(k = 0, i = 2; i <= n; ++i) {
		while(k && a[k + 1] != a[i]) k = phi[k];
		if(a[k + 1] == a[i]) ++k;
		
		phi[i] = k;
	}
	
	/*dbg_v(a + 1, n);
	for(i = 1; i <= m; ++i)
		dbg_v(b[i] + 1, n - m + 1);*/
	
	for(i = 1; i <= n - m + 1; ++i)
		if(ret = kmp(i)) {
			cout << ret <<  ' ' << i << '\n';
			return 0;
		}
	
	return 0;
}
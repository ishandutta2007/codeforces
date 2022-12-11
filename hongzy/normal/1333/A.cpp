#include <bits/stdc++.h>
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
 
const int N = 110 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int t, n, m, a[N][N]; 
int main() {
	scanf("%d", &t);
	while(t --) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				a[i][j] = (i + j) & 1;
		if(n * m & 1) {
			for(int i = 1; i <= n; i ++, puts(""))
				for(int j = 1; j <= m; j ++)
					printf("%c", !a[i][j] ? 'B' : 'W');
			continue ;
		}
		a[1][1] = 1;
		for(int i = 1; i <= n; i ++, puts(""))
			for(int j = 1; j <= m; j ++)
				printf("%c", a[i][j] ? 'B' : 'W');
	}
	return 0;
}
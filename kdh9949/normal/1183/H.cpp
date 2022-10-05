#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 105, K = 26;
const ll M = ll(1e13);

int n, nx[N][K];
ll k, r, d[N][N], c[N];
char s[N];

int main(){
	scanf("%d%lld%s", &n, &k, s + 1);
	fill(nx[n+1], nx[n+1]+K, n+1);
	for(int i = n; i >= 1; i--){
		for(int j = 0; j < K; j++) nx[i][j] = nx[i+1][j];
		nx[i][s[i] - 'a'] = i;
		d[i][1] = 1;
		for(int j = 2; j <= n; j++){
			for(int t = 0; t < K; t++)
				d[i][j] = (d[i][j] + d[nx[i+1][t]][j-1]) % M;
		}
	}
	c[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < K; j++) c[i] = (c[i] + d[nx[1][j]][i]) % M;
	}
	for(int i = n; i >= 0; i--){
		ll v = min(k, c[i]);
		r += (n - i) * v;
		k -= v;
	}
	if(k) puts("-1");
	else printf("%lld\n", r);
}
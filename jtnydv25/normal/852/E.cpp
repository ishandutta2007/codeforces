#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int deg[N];
int main(){
	int n, l = 0, a, b;
	scanf("%d", &n);
	if(n == 1){
		printf("%d\n", 1);
		return 0;
	}
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		deg[a]++;
		deg[b]++;
	}
	for(int i = 1; i <= n; i++) l += (deg[i] == 1);
	int nl = (n - l);
	int prod = 1;
	for(int i = 1; i <= nl; i++) prod = (prod << 1) % mod;
	int ans = nl * 1ll * prod % mod;
	prod = (prod << 1) % mod;
	ans = (ans + prod * 1ll * l) % mod;
	printf("%d", ans);
}
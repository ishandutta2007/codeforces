#include <bits/stdc++.h>
#define maxn 50

using namespace std;

typedef long long ll;

int n, k, q, x;
ll a[maxn];
bool vis[maxn];

void dfs(int i, ll x, ll y){
	//printf("%d %lld %lld--\n", i, x, y);
	if(i > k){
		if(__builtin_popcountll(x) < n || __builtin_popcountll(y) + __builtin_ctzll(y) < n) printf("REJECTED"), exit(0);
		vis[__builtin_popcountll(y)] = true;
		return;
	}
	int cnt = __builtin_popcountll(a[i]);
	int min0 = __builtin_popcountll(a[i] & x) - __builtin_popcountll(a[i] & y);
	int max0 = min0 + cnt - __builtin_popcountll(a[i] & x);
	//printf("%d %lld %lld %d %d--\n", i, x, y, min0, max0);
	ll j = a[i];
	for(int c = 0;c <= cnt;c++, j -= j & -j){
		if(min0 <= c && c <= max0) dfs(i + 1, x | a[i], (y | a[i]) ^ a[i] ^ j);
	}
}

int main(){
	scanf("%d%d", &n, &k);
	if(n == 1) return printf("ACCEPTED"), 0;
	for(int i = 1;i <= k;i++){
		scanf("%d", &q);
		while(q--) scanf("%d", &x), a[i] |= 1ll << (x - 1);
	}
	dfs(1, 0, 0);
	for(int i = 0;i <= n;i++) if(!vis[i]) return printf("REJECTED"), 0;
	printf("ACCEPTED");
}
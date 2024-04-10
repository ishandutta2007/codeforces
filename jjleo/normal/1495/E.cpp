#include <bits/stdc++.h>
#define maxn 5000086

using namespace std;

int n, m;
int p, pp, k, b, w;
int t[maxn], a[maxn], ans[maxn];
long long sum[2];

int seed, base;
inline int rnd(){
	int ret = seed;
	seed = (1ll * seed * base + 233) % 1000000007;
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d%d", &p, &k, &b, &w);
		seed = b;
		base = w;
		for(int j = pp + 1;j <= p;j++){
			t[j] = rnd() % 2;
			a[j] = (rnd() % k) + 1;
		}
		pp = p;
	}
	for(int i = 1;i <= n;i++) sum[t[i]] += a[i];
	if(!sum[0] || !sum[1]){
		ans[1] = 1;
	}else{
		int x = 1;
		if(sum[t[x]] > sum[t[x] ^ 1]){
			ans[1]++, a[1]--;
			while(t[x] == t[1]) x++;
		}
		int T = t[x];
		long long val = 0;
		for(int i = 1;i <= 2 * n;i++, x++){
			if(x > n) x = 1;
			if(t[x] == T) val += a[x], ans[x] += a[x], a[x] = 0;
			else{
				int cnt = min(1ll * a[x], val);
				ans[x] += cnt, a[x] -= cnt, val -= cnt;
			}
		}
	}
	int Ans = 1;
	const int p = 1e9 + 7;
	for(int i = 1;i <= n;i++) Ans = 1ll * Ans * ((ans[i] ^ (1ll * i * i)) % p + 1) % p;
	printf("%d", Ans);
}
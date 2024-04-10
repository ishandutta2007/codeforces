#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

/*int n;
int vis[maxn];
int last[3];
int val[maxn][3];
int cnt;

int main(){
	for(int i = 1;i <= 500;i++){
		if(vis[i]) continue;
		int tag = 0;
		for(int j = i + 1;j <= 1000;j++){
			if(vis[j]) continue;
			for(int k = j + 1;k <= 1000;k++){
				if(vis[k]) continue;
				if((i ^ j) == k){
					tag = true; 
					printf("%d %d %d\n", i, j, k);
					//printf("%d %d %d %d %d %d\n", i, j, k, i ^ last[0], j ^ last[1], k ^ last[2]); 
					val[++cnt][0] = i,val[cnt][1] = j, val[cnt][2] = k;
					vis[i] = vis[j] = vis[k] = 1;
				} 
			} 
			if(tag) break;
		} 
	} 
	for(int i = 6;i <= 100;i += 4) printf("%d\n", val[i][1] - val[i - 4][1]);
}*/

int t;
ll n, m;
ll a, b;

ll solve(ll x, ll y){
	if(!y) return x;
	ll len = y / 4;
	if(x <= len) return solve(x, y >> 2);
	if(x <= len * 2) return solve(x - len, y >> 2) + len * 2;
	if(x <= len * 3) return solve(x - len * 2, y >> 2) + len * 3;
	return solve(x - len * 3, y >> 2) + len;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n), 
		m = (n - 1) / 3 + 1;
		ll k = 1;
		while(m > 0) m -= k, k <<= 2;
		k >>= 2;
		a = (k << 1) - 1 + m;
		if(n % 3 == 1){
			printf("%lld\n", a);
			continue;
		}
		b = solve(a - k + 1, k) + (k << 1) - 1;
		printf("%lld\n", n % 3 ? b : (a ^ b));
		//if(n % 3 == 0) puts("");
	}
}
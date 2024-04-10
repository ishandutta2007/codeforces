#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 998244353;

int t, n, k;
int a[maxn];

int solve(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= k;i++) if(a[n - i + 1] > 0) return 0;
	int ans = 1;
	for(int i = 1;i <= n - k;i++){
		if(a[i] == -1) ans = 1ll * ans * (i + k) % p;
		else if(a[i] == 0) ans = 1ll * ans * (k + 1) % p;
		else if(a[i] + k > i + k - 1) return 0;
	}
	for(int i = 1;i <= k;i++) ans = 1ll * ans * i % p;
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--) printf("%d\n", solve());
}
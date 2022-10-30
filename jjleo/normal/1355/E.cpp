#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, A, B, C;
int a[maxn];


inline ll cal(int k){
	ll x = 0, y = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] > k) y += a[i] - k;
		else x += k - a[i];
	}
	ll z = min(x, y);
	//printf("%d %lld %lld--\n", k, x, y);
	return min(x * A + y * B, z * C + (x - z) * A + (y - z) * B);
}

int main(){
	scanf("%d%d%d%d", &n, &A, &B, &C);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int l = 0, r = a[n] + 1;
	ll lans = 0, rans = 0;
	while(l < r){
		int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
		lans = cal(lmid), rans = cal(rmid);
		if(lans <= rans) r = rmid - 1;
		else l = lmid + 1;
	}
	printf("%lld", min(lans, rans));
	/*for(int i = 1;i <= n;i++){
		ll x = (i - 1) * (a[i] - a[i - 1]) - a[i - 1], y = a[n] - a[i] - (n - i) * (a[i] - a[i - 1]);
		ll z = min(x, y);
		ans = min(ans, min(x * A + y * B, z * C + (x - z) * A + (y - z) * B));
	}
	for(int j = -1;j <= 1;j++){
		ll x = 0, y = 0, k = a[n] / n + j;
		if(j < 0) continue;
		for(int i = 1;i <= n;i++){
			if(a[i] - a[i - 1] > k) x += a[i] - a[i - 1] - k;
			else y += k - (a[i] - a[i - 1]);
		}
		ll z = min(x, y);
		ans = min(ans, min(x * A + y * B, z * C + (x - z) * A + (y - z) * B));
	}
	printf("%lld", ans);*/
}
#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n;
ll a[maxn];

ll st[maxn][22];
int lg[maxn];

ll Gcd(int l, int r){
	return __gcd(st[l][lg[r - l + 1]], st[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
}

int main(){
	for(int i = 2;i <= maxn;i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		if(n == 1){
			puts("1");
			continue;
		}
		for(int i = 1;i < n;i++) a[i] -= a[i + 1], a[i] = abs(a[i]), st[i][0] = a[i];
		for(int j = 1;j <= 20;j++){
			for(int i = 1;i + (1 << j) - 1 < n;i++){
				st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
		int ans = 1;
		for(int i = 1;i < n;i++){
			if(a[i] == 1) continue;
			int l = 1, r = i, mid;
			while(l < r){
				mid = l + r >> 1;
				if(Gcd(mid, i) > 1) r = mid;
				else l = mid + 1;
			}
			ans = max(ans, i - l + 2);
		}
		printf("%d\n", ans);
	}
}
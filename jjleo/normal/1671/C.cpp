#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		ll ans = 0, sum = 0;
		for(int i = 1;i <= n;i++){
			if(sum + a[i] > x) break;
			int l = 0, r = x, mid;
			while(l < r){
				mid = (l + r >> 1) + 1;
				if(sum + 1ll * (i - 1) * mid + a[i] + mid <= x) l = mid;
				else r = mid - 1;
			}
			ans += l + 1;
			sum += a[i];
		}
		printf("%lld\n", ans);
	}
}
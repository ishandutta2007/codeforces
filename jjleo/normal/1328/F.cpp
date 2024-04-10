#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, k;
ll ans = (1ll << 63) - 1;
ll a[maxn];
ll b[maxn], c[maxn];
ll l[maxn], r[maxn];
ll sum[maxn];

int cnt;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		if(a[i] != a[i - 1]) b[++cnt] = a[i], c[cnt]++;
		else c[cnt]++;
		if(c[cnt] >= k){
			printf("0");
			return 0;
		}
	}
	for(int i = 1;i <= cnt;i++) sum[i] = sum[i - 1] + c[i];
	for(int i = 1;i <= cnt;i++) l[i] = l[i - 1] + 1ll * sum[i - 1] * (b[i] - b[i - 1]);
	for(int i = cnt;i;i--) r[i] = r[i + 1] + 1ll * (sum[cnt] - sum[i]) * (b[i + 1] - b[i]);
	
	int j = 1;
	while(sum[j] < k) j++;
	for(int i = 1;i <= j;i++){
		if(sum[i] < k){
			ans = min(ans, l[i] + r[i] - (sum[n] - sum[i] - (k - sum[i])));
		}else{
			ans = min(ans, l[i] - (sum[i] - k));
		}
	}
	j = cnt;
	while(sum[cnt] - sum[j - 1] < k) j--;
	for(int i = cnt;i >= j;i--){
		if(sum[cnt] - sum[i - 1] < k){
			ans = min(ans, l[i] + r[i] - (sum[i - 1] - (k - (sum[cnt] - sum[i - 1]))));
		}else{
			ans = min(ans, r[i] - (sum[cnt] - sum[i - 1] - k));
		}
	}
	printf("%lld", ans);
}
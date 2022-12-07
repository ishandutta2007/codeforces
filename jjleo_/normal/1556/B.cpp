#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], sum[2], cnt[2];
int b[maxn], p[maxn];

inline void add(int x, int y){
	for(;x <= n;x += x & -x) p[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += p[x];
	return sum;
}

long long cal(){
	for(int i = 1;i <= n;i++) p[i] = 0;
	long long ans = 0;
	for(int i = 1;i <= n;i++) ans += query(n) - query(b[i]), add(b[i], 1);
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum[0] = sum[1] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum[a[i] &= 1]++;
		long long ans = 1e11;
		if(sum[0] - sum[1] == 1 || sum[0] == sum[1]){
			cnt[0] = 1, cnt[1] = 2;
			for(int i = 1;i <= n;i++) b[i] = cnt[a[i]], cnt[a[i]] += 2;
			ans = min(ans, cal());
		}
		if(sum[1] - sum[0] == 1 || sum[0] == sum[1]){
			cnt[1] = 1, cnt[0] = 2;
			for(int i = 1;i <= n;i++) b[i] = cnt[a[i]], cnt[a[i]] += 2;
			ans = min(ans, cal());
		}
		printf("%lld\n", ans == 1e11 ? -1 : ans);
	}
}
#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int n;
int a[maxn], b[maxn], c[maxn];
long long ans = 1;
int x;

inline long long fpow(long long x, long long y){
	long long ans = 1;
	while(y){
		if(y & 1) ans *= x;
		x *= x, y >>= 1;
	} 
	return ans;
}

int main(){
	scanf("%d", &n);
	memset(a, 0x3f, sizeof(a)), memset(b, 0x3f, sizeof(b));
	for(int j = 1;j <= n;j++){
		scanf("%d", &x);
		int y = x;
		for(int i = 2;1ll * i * i <= y && x != 1;i++){
			int cnt = 0;
			while(x % i == 0) x /= i, cnt++;
			if(cnt <= a[i]) b[i] = a[i], a[i] = cnt;
			else b[i] = min(b[i], cnt);
			if(cnt) c[i]++;
		}
		if(x != 1){
			if(1 <= a[x]) b[x] = a[x], a[x] = 1;
			else b[x] = min(b[x], 1);
			c[x]++;
		}
	}
	for(int i = 2;i < maxn;i++){
		//printf("%d %d %lld--\n", i, b[i], ans);
		if(c[i] < n - 1) continue;
		if(c[i] == n - 1 && a[i]) b[i] = a[i];
		ans *= fpow(i, b[i] < maxn ? b[i] : a[i]);
	}
	printf("%lld", ans);
}
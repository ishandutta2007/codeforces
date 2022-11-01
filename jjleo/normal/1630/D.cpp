#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n, m, g, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m), g = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		while(m--){
			scanf("%d", &x);
			g = __gcd(g, x);
		}
		long long ans1 = 0, ans2 = 0, sum = 0;
		for(int i = 1;i <= g;i++){
			int mn = 1e9, cnt = 0;
			for(int j = i;j <= n;j += g){
				mn = min(mn, abs(a[j]));
				cnt += a[j] < 0;
				sum += abs(a[j]);
			}
			if(cnt & 1) ans1 += mn * 2;
			else ans2 += mn * 2; 
		}
		printf("%lld\n", sum - min(ans1, ans2));
	}
}
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			long long x = a[i], sum = 0;
			for(int j = 1;j <= n;j++) if(i ^ j){
				int y = a[j];
				while(y % 2 == 0) x *= 2, y /= 2;
				sum += y;
			}
			ans = max(ans, sum + x);
		}
		printf("%lld\n", ans);
	}
}
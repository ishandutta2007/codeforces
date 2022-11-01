#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k, z;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &k, &z);
		int ans = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), a[i] += a[i - 1];
		for(int i = 2;i - 1 <= k;i++){
			int sum = a[i];
			int cnt = min(max(0, (k - (i - 1)) / 2), z);
			sum += cnt * (a[i] - a[i - 2]);
			if(cnt < z && k - (i - 1) - cnt * 2 == 1) ans = max(ans, sum + a[i - 1] - a[i - 2]);
			sum += a[i + k - (i - 1) - cnt * 2] - a[i];
			//printf("%d %d %d--\n", i, cnt, sum);
			ans = max(ans, sum);
		}
		printf("%d\n", ans);
	} 
}
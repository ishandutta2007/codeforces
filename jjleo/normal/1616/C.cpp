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
		int ans = n - 1;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				double d = 1.0 * (a[j] - a[i]) / (j - i);
				int sum = 0;
				for(int k = 1;k <= n;k++) sum += abs(a[i] + (k - i) * d - a[k]) > 1e-6;
				ans = min(ans, sum);
			}
		}
		printf("%d\n", ans);
	}
}
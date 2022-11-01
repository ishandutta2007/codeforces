#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
int a[maxn];
int w[maxn];
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		ans = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= k;i++) scanf("%d", &w[i]);
		sort(a + 1, a + 1 + n), sort(w + 1, w + 1 + k);
		int m = n - k; 
		for(int i = 1;i <= k;i++){
			ans += a[n - i + 1];
			if(w[i] - 2 >= 0){
				m -= w[i] - 2;
				ans += a[m];
				m--;
			}else{
				ans += a[n - i + 1];
			}
		} 
		printf("%lld\n", ans);
	}
}
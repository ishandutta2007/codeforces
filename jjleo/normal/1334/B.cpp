#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;
long long a[maxn];
long long sum;
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x), sum = 0;
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), sum += a[i]; 
		if(sum / n >= x){
			printf("%d\n", n);
			continue;
		}
		sort(a + 1, a + 1 + n);
		a[n + 1] = 0;
		for(int i = n;i;i--) a[i] += a[i + 1];
		ans = 0;
		for(int i = n;i;i--){
			if(a[i] / (n - i + 1) >= x) ans = n - i + 1;
			else break;
		}
		printf("%d\n", ans);
	}
}
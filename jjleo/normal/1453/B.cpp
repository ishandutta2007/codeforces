#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		long long sum = 0, ans = 1e18;
		for(int i = n;i > 1;i--) sum += abs(a[i] - a[i - 1]);
		ans = sum;
		for(int i = 1;i <= n;i++){
			int x = 0;
			if(i > 1){
				if(i == n) x = max(x, abs(a[i] - a[i - 1]));
				else x = max(x, abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i - 1]) + abs(a[i + 1] - a[i]));
			}
				
			//if(i > 1) x = max(x, abs(a[i] - a[i - 1]));
			if(i > 1 && i < n) x = max(x, abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i - 1])); 
			if(i == 1) x = max(x, abs(a[i] - a[i + 1]));
			//if(i < n) x = max(x, abs(a[i] - a[i + 1]));
			ans = min(ans, sum - x);
		}
		printf("%lld\n", ans);
	}
}
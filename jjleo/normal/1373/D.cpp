#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n;
int a[maxn];
ll sum, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < n;i++) scanf("%d", &a[i]);
		sum = 0;
		for(int i = 0;i < n;i += 2) sum += a[i];
		ans = 0;
		ll x = 0, y = 0;
		for(int i = 0;i + 1 < n;i += 2){
			x += -a[i] + a[i + 1];
			ans = max(ans, x - y);
			y = min(y, x);
		}
		x = 0, y = 0;
		for(int i = 1;i + 1 < n;i += 2){
			x += a[i] - a[i + 1];
			ans = max(ans, x - y);
			y = min(y, x);
		}
		printf("%lld\n", sum + ans);
	}
}
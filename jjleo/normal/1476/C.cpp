#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
ll a[maxn], b[maxn], c[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%lld", &c[i]);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%lld", &b[i]);
		ll sum = 0, ans = 0, mx = -1e18;
		for(int i = 2;i <= n;i++){
			if(a[i] == b[i]) sum = 2, mx = 0;
			else mx = max(mx, abs(a[i] - b[i]) - (sum + c[i - 1] - 1 - abs(a[i] - b[i]))), sum += 2 + c[i - 1] - 1 - abs(a[i] - b[i]);
			ans = max(ans, sum + c[i] - 1 + mx);
		}
		printf("%lld\n", ans);
	}
}
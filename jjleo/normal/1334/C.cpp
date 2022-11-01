#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int t;
int n;

ll a[maxn], b[maxn], c[maxn], sum;
ll ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < n;i++){
			scanf("%lld%lld", &a[i], &b[i]);
		}
		if(n == 1){
			printf("%lld\n", a[0]);
			continue;
		}
		sum = 0, ans = 1e18;
		for(int i = 0;i < n;i++){
			sum += (c[i] = max(0ll, a[i] - b[(i - 1 + n) % n]));
			ans = min(ans, a[i] - c[i]);
		}
		printf("%lld\n", sum + ans);
	}
}
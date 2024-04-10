#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

int n, k;
int a[maxn];
ll ans;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, greater<int>());
	ll sum = 0;
	int I = n + 1;
	for(int i = 1;i <= n;i++){
		ans += sum;
		sum += a[i];
		if(sum < 0){
			I = i;
			a[i] = sum;
			break;
		} 
	}
	for(int i = n;i >= I;i--){
		ans += 1ll * (n - i) / (k + 1) * a[i];
	}
	printf("%lld", ans);
	
}
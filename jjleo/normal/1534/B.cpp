#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

typedef long long ll;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		a[0] = a[n + 1] = 0;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] > a[i - 1] && a[i] > a[i + 1]) ans += a[i] - max(a[i - 1], a[i + 1]), a[i] = max(a[i - 1], a[i + 1]);
		}
		for(int i = 1;i <= n + 1;i++) ans += abs(a[i] - a[i - 1]);
		printf("%lld\n", ans);
	}
}
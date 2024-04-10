#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
map<int, ll> a;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		a.clear();
		scanf("%d", &n);
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			ans += (n - i + 1) * a[x];
			a[x] += i;
		}
		printf("%lld\n", ans);
	}
		
}
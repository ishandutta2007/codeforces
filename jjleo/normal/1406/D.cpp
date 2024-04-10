#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
long long a[maxn], ans;
int l, r, x; 

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = n;i > 1;i--) ans += max(0ll, a[i] -= a[i - 1]);
	scanf("%d", &q);
	printf("%lld\n", max((a[1] + ans) / 2, a[1] + ans - (a[1] + ans) / 2));
	while(q--){
		scanf("%d%d%d", &l, &r, &x);
		if(l > 1) ans -= max(0ll, a[l]);
		a[l] += x;
		if(l > 1) ans += max(0ll, a[l]);
		if(r < n){
			ans -= max(0ll, a[r + 1]), a[r + 1] -= x, ans += max(0ll, a[r + 1]);
		}
		printf("%lld\n", max((a[1] + ans) / 2, a[1] + ans - (a[1] + ans) / 2));
	}
}
#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ll sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), sum += b[i];
		printf("%lld\n", sum - *max_element(b + 1, b + 1 + n));
	}
}
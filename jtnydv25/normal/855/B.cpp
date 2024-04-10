#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &x)
const int N = 1e5 + 5;
int A[N];
const ll INF = 3e18 + 100;
int main(){
	int n, p, q, r;
	sd(n); sd(p); sd(q); sd(r);
	for(int i = 1; i <= n; i++){
		sd(A[i]);
	}
	ll mx1 = -INF, mx2 = -INF, mx3 = -INF;
	for(int i = n; i >= 1; i--){
		mx1 = max(mx1, r * 1ll * A[i]);
		mx2 = max(mx2, q * 1ll * A[i] + mx1);
		mx3 = max(mx3, p * 1ll * A[i] + mx2);
	}
	printf("%lld\n", mx3);
}
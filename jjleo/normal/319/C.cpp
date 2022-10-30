#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

typedef long long ll;

int n;
ll a[maxn], b[maxn], f[maxn];
int q[maxn], l, r;

inline double k(int i, int j){
	return 1.0 * (f[i] - f[j]) / (b[j] - b[i]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%lld", &b[i]);
	f[1] = 0, q[0] = 1;
	for(int i = 2;i <= n;i++){
		while(l < r && k(q[l], q[l + 1]) <= a[i]) ++l;
		f[i] = f[q[l]] + a[i] * b[q[l]];
		//printf("%d %d %lld--\n", i, q[l], f[i]);
		while(l < r && k(q[r], q[r - 1]) >= k(q[r], i)) --r;
		q[++r] = i;
	}
	printf("%lld", f[n]);
}
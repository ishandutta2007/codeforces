#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k, x, y;
long long a[maxn];
vector<int> v;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 2;i <= n;i++){
		printf("or %d %d\n", 1, i), fflush(stdout);
		scanf("%d", &x);
		printf("and %d %d\n", 1, i), fflush(stdout);
		scanf("%d", &y);
		a[i] = 1ll * x + y;
	}
	printf("or %d %d\n", 2, 3), fflush(stdout);
	scanf("%d", &x);
	printf("and %d %d\n", 2, 3), fflush(stdout);
	scanf("%d", &y);
	a[1] = 1ll * x + y;
	a[1] -= a[2];
	a[3] += a[1];
	a[3] /= 2;
	a[1] = -(a[1] - a[3]);
	for(int i = 2;i <= n;i++) if(i ^ 3) a[i] -= a[1];
	sort(a + 1, a + 1 + n);
	printf("finish %lld\n", a[k]), fflush(stdout);
}
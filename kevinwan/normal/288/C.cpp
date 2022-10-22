#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int main() {
	int n, i,j;
	scanf("%d", &n);
	n++;
	for (i = 1 << 20; i; i >>= 1) {
		if (!(n&i))continue;
		for (j = 0; j < i; j++)v.push_back(i - 1 - j);
		for (j = 1; j <= n % i; j++)v[v.size() - j] += i;
	}
	printf("%lld\n", 1LL * n*(n - 1));
	for (int x : v)printf("%d ", x);
	getchar(); getchar();
}
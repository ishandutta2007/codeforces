#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
ll fib[51];
int main() {
	int n,i;
	ll k;
	fib[0]=1,fib[1] = 1;
	scanf("%d%lld", &n, &k);
	for (i = 2; i <= n; i++)fib[i] = fib[i - 1] + fib[i - 2];
	for (i = 1; i <= n; ) {
		if (k > fib[n - i])k -= fib[n - i], printf("%d %d ", i + 1, i), i += 2;
		else printf("%d ", i), i++;
	}
	getchar(); getchar();
}
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

int n;
ll a[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + a[i] * a[n - 1 - i]) % 10007;
	printf("%I64d\n", ans);
	return 0;
}
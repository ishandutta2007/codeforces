#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct thing {
	double pp = 1;
	ll p = 1, a = 0, b = 0;
};
ll a[200000];
thing t[200000];
int main() {
	ll n, k, start = 0, end = 0, ans = 0;
	scanf("%lld%lld", &n, &k);
	int i, j;
	for (i = 0; i < n; i++)scanf("%lld", a + i);
	t[0].pp=t[0].p = t[0].a = t[0].b = a[0];
	if (k == 1)ans++;
	for (i = 1; i < n; i++) {
		for (j = start; j <=end; j++) {
			if (t[j].pp*a[i]>=1e15)start++;
			else {
				t[j].pp *= a[i];
				t[j].p *= a[i];
				t[j].a += a[i];
				t[j].b += a[i];
				if (t[j].p%k != 0)continue;
				if (t[j].a*k <= t[j].p&&t[j].b*k >= t[j].p)ans++;
			}
		}
		if (a[i] == 1&&t[end].p==1) { t[end].a=1; }
		else {
			end++;
			t[end].pp=t[end].p = t[end].a = t[end].b = a[i];
		}
		if (k == 1)ans++;
	}
	printf("%lld", ans);
	getchar(); getchar();
}
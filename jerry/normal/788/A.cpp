#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100005], tmp[100005];

ll slv(ll *x, int n)
{
	n--;
	for (int i = 0;i < n;i++) tmp[i] = abs(x[i+1]-x[i]);
	ll a = 0, s = 0, c = 0;
	for (int i = 0;i < n;i++)
	{
		if (i&1) c -= tmp[i]; else c += tmp[i];
		a = max(a, c-s);
		if (i&1) s = min(s, c);
	}
	return a;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%lld", arr+i);
	printf("%lld\n", max(slv(arr, n), slv(arr+1, n-1)));
	return 0;
}
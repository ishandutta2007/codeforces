#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int p[1000005], q[1000005], n, m, a, b;
ll x[1000005], _, __;

int g(int i) { return p[i]==i?i:p[i]=g(p[i]); }

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) p[i] = i;
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d", &a, &b); --a, --b;
		p[g(a)] = g(b);
		if (a != b) ++x[a], ++x[b];
		else __++;
		++q[a], ++q[b];
	}
	for (int i = 0;i < n;i++) if (g(i) != g(a) && q[i])
	{
		printf("0\n");
		return 0;
	}
	_ = __*(__-1)/2+(m-__)*__;
	for (int i = 0;i < n;i++) _ += x[i]*(x[i]-1)/2;
	printf("%lld\n", _);
	return 0;
}
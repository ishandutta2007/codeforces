#include <bits/stdc++.h>
using namespace std;

int s1[100005], s2[100005];
int a[100005];
int n, d, b;

bool chk(int va)
{
	int rem = 0;
	long long j = 0;
	for (int i = 0;i < (n+1)/2;i++)
	{
		for (;j <= i+1ll*(i+1)*d && j < n;j++) rem += s1[j];
		if (i >= va) rem -= b;
		if (rem < 0) return false;
	}
	rem = 0;
	j = n-1;
	for (int i = n-1;i >= (n+1)/2;i--)
	{
		for (;j >= i-1ll*(n-i)*d && j >= 0;j--) rem += s2[j];
		if (n-i > va) rem -= b;
		if (rem < 0) return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d", &n, &d, &b);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	int cu = 0;
	for (int i = 0;i < n;i++)
	{
		int w = min(a[i], (n+1)/2*b-cu);
		s1[i] = w;
		s2[i] = a[i] - w;
		cu += w;
	}
	int lo = -1, hi = n;
	while (lo+1 < hi)
	{
		int mid = (lo+hi) / 2;
		if (chk(mid)) hi = mid;
		else lo = mid;
	}
	printf("%d\n", hi);
	return 0;
}
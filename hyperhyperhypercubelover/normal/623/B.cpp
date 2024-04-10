#include <cstdio>
#include <algorithm>

using namespace std;

int a[1111111];
int d[333], dn;

void f(int x)
{
	int i;
	for (i = 2; i*i <= x; i++) if (!(x%i))
	{
		d[dn++] = i;
		while (!(x%i)) x /= i;
	}
	if (x > 1) d[dn++] = x;
}

int main()
{
	long long L, R, t, r = 9e18;
	int x, y;
	int i, j, k, n;
	scanf("%d%d%d", &n, &x, &y);
	for (i = 0; i < n; i++) scanf("%d", a + i);
	for (i = -1; i <= 1; i++)
	{
		f(a[0] + i);
		f(a[n - 1] + i);
	}
	sort(d, d + dn);
	dn = unique(d, d + dn) - d;
	while (dn--)
	{
		L = x;
		R = 0;
		for (i = j = 0; i < n; i++)
		{
			if (!(a[i] % d[dn]))
			{
				t = (long long)y*j - (long long)x*i;
				if (t < L)
				{
					L = t;
					k = i + 1;
				}
			}
			else if (!((a[i] + 1) % d[dn]) || !((a[i] - 1) % d[dn]))
			{
				j++;
				t = (long long)y*j - (long long)x*i;
				if (t < L)
				{
					L = t;
					k = i + 1;
				}
			}
			else break;
		}
		if (i < n)
		{
			for (i = n - 1, j = 0; i >= 0; i--)
			{
				if (!(a[i] % d[dn]))
				{
					t = (long long)y*j - (long long)x*(n - i);
					if (t < R) R = t;
				}
				else if (!((a[i] + 1) % d[dn]) || !((a[i] - 1) % d[dn]))
				{
					j++;
					t = (long long)y*j - (long long)x*(n - i);
					if (t < R) R = t;
				}
				else break;
			}
			R += L + (long long)x*(n - 1);
			if (r > R) r = R;
		}
		else
		{
			R = 0;
			t = 0;
			for (i = j = 0; i < n - 1; i++)
			{
				t -= x;
				if (a[i] % d[dn]) t += y;
				if (R < t) R = t;
				if (t < 0) t = 0;
			}
			R = -R;
			for (i = 0; i < n; i++) if (a[i] % d[dn]) R += y;
			if (R > L + (long long)x*(n - 1)) R = L + (long long)x*(n - 1);
			if (r > R) r = R;
		}
	}
	printf("%I64d", r);
}
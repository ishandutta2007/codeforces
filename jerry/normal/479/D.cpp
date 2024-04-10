#include <cstdio>

#define A  a[i]-x
#define B  a[i]-y
#define C  a[i]-x-y
#define D  a[i]+x-y

int a[100005];
int n;
int l;
int x;
int y;

bool search(int val)
{
	int lo = 0, hi = n;
	while (lo+1 < hi)
	{
		int mid = (lo+hi) >> 1;
		if (a[mid] < val)
			lo = mid+1;
		else if (a[mid] > val)
			hi = mid;
		else
		{
			lo = mid;
			break;
		}
	}
	return (a[lo] == val);
}

int main()
{
	scanf("%d%d%d%d", &n, &l, &x, &y);
	for (int i = 0;i < n;i++)
		scanf("%d", a+i);
	bool flag1 = false, flag2 = false;
	for (int i = 0;i < n;i++) if (search(A))
	{
		flag1 = true;
		break;
	}
	for (int i = 0;i < n;i++) if (search(B))
	{
		flag2 = true;
		break;
	}
	if (!flag1 || !flag2)
		goto one;
	printf("0\n");
	return 0;
one:
	if (flag1 && !flag2)
	{
		printf("1\n%d\n", y);
		return 0;
	} else if (flag2 && !flag1)
	{
		printf("1\n%d\n", x);
		return 0;
	}
	flag1 = false;
	flag2 = false;
	for (int i = 0;i < n;i++) if (search(C))
	{
		printf("1\n%d\n", a[i]-x);
		return 0;
	}
	for (int i = 0;i < n;i++) if (a[i]+x <= l && search(D))
	{
		printf("1\n%d\n", a[i]+x);
		return 0;
	}
	for (int i = 0;i < n;i++) if (a[i]-y >= 0 && search(D))
	{
		printf("1\n%d\n", a[i]-y);
		return 0;
	}
	printf("2\n%d %d\n", x, y);
	return 0;
}
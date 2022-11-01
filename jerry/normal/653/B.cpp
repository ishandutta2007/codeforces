#include <bits/stdc++.h>
using namespace std;

char A[37][4], B[37][4];
int a[37], b[37];
bool dp[300000];
int n, q;

int foo(char* str)
{
	int ret = 0;
	for (int i = 1;i >= 0;i--) if (str[i])
		ret = (ret<<3)|(str[i]-'a'+1);
	return ret;
}

int foo(int at, int add)
{
	return (((at>>6)<<3)|add);
}

bool can(int at, int rem)
{
	return (at&63) == rem;
}

bool valid(int at)
{
	while (at)
	{
		if (!((at&7) >= 1 && (at&7) <= 6))
			return false;
		at >>= 3;
	}
	return true;
}

int len(int at)
{
	int ret = 0;
	for (;at;at >>= 3)
		ret++;
	return ret;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0;i < q;i++) scanf("%s%s", A[i], B[i]);
	for (int i = 0;i < q;i++) a[i] = foo(A[i]), b[i] = foo(B[i]);
	dp[1] = true;
	for (int i = 9;i < 300000;i++) if (valid(i))
	{
		for (int j = 0;j < q;j++) if (can(i, a[j]))
		{
			if (dp[foo(i, b[j])])
			{
				dp[i] = true;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0;i < 300000;i++) if (len(i) == n)
		ans += dp[i];
	printf("%d\n", ans);
	return 0;
}
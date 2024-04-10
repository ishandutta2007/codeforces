#include <bits/stdc++.h>
using namespace std;

int foo(int x)
{
	int ret = 0, len = 1;
	while (len < x)
	{
		ret++;
		len *= 7;
	}
	if (ret == 0) ret++;
	return ret;
}

vector<int> d;
int l1, l2;
int n, m;
int ans;

bool check()
{
	int a = 0, b = 0;
	for (int i = 0;i < l1;i++) a = a*7+d[i];
	for (int i = l1;i < l1+l2;i++) b = b*7+d[i];
	if (a < n && b < m) return true;
	return false;
}

void bf(int msk, int at)
{
	if (at == l1+l2)
	{
		if (check()) ans++;
		return;
	}
	for (int i = 0;i < 7;i++) if (!(msk&(1<<i)))
	{
		d.push_back(i);
		bf(msk|(1<<i), at+1);
		d.pop_back();
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	l1 = foo(n), l2 = foo(m);
	if (l1+l2 > 7)
	{
		printf("0\n");
		return 0;
	}
	bf(0, 0);
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, k, a;

int main()
{
	scanf("%d%d", &n, &k);
	k = 240 - k;
	for (int i = 1;i <= n && k >= 5*i;i++) k -= 5*i, a++;
	printf("%d\n", a);
	return 0;
}
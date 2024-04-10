#include <bits/stdc++.h>
using namespace std;

char a;

int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k); k--;
	if (k&1) a = 'R'; else a = 'L'; k >>= 1;
	printf("%d %d %c\n", k/m+1, k%m+1, a);
	return 0;
}
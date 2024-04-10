#include <bits/stdc++.h>
using namespace std;

int occ[12], n, m, x;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) { scanf("%d", &x); occ[x]++; } x = 0;
	for (int i = 0;i < 12;i++) for (int j = i+1;j < 12;j++) x += occ[i]*occ[j];
	printf("%d\n", x); return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	if (n&1) printf("0\n");
	else if (n%4 == 2) printf("%d\n", n/4);
	else printf("%d\n", n/4-1);
	return 0;
}
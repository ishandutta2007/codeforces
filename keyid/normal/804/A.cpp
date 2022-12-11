#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if (n&1) n++;
	printf("%d",n/2-1);
	return 0;
}
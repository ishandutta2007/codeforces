#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long big;

int main()
{
	big a, b;
	int tot = 1;
	scanf("%lld%lld", &a, &b);
	for(big i = a + 1; i <= b && tot; i++)
		(tot *= i % 10) %= 10;
	printf("%d\n", tot);
	return 0;
}
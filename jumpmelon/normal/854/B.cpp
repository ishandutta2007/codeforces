#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if(n <= k || k == 0)
		puts("0 0");
	else
	{
		if(k >= n - k - k)
			printf("1 %d\n", n - k);
		else
			printf("1 %d\n", k * 2);
	}
	return 0;
}
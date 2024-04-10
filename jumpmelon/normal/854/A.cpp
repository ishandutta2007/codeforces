#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int a = n / 2, b = n - a; a > 0; a--, b++)
		if(gcd(a, b) == 1)
		{
			printf("%d %d\n", a, b);
			break;
		}
	return 0;
}
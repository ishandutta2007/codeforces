#include <cstdio>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = a+b+c;
	if (a*b+c > ans)
		ans = a*b+c;
	if (a+b*c > ans)
		ans = a+b*c;
	if (a*b*c > ans)
		ans = a*b*c;
	if ((a+b)*c > ans)
		ans = (a+b)*c;
	if (a*(b+c) > ans)
		ans = a*(b+c);
	printf("%d\n", ans);
	return 0;
}
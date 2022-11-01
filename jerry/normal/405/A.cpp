#include <cstdio>
#include <algorithm>

int num[100], n;
int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", num+i);
	std::sort(num, num+n);
	for (int i = 0;i < n;i++) printf("%d ", num[i]);
	return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

char x[205];
int count1, count2;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf(" %c", x+i);
		if (x[i] == 'x')
			count1++;
		else
			count2++;
	}
	printf("%d\n", abs(count1-count2)>>1);
	for (int i = 0;i < n && count1 > count2;i++) if (x[i] == 'x')
	{
		x[i] = 'X';
		count1--;
		count2++;
	}
	for (int i = 0;i < n && count1 < count2;i++) if (x[i] == 'X')
	{
		x[i] = 'x';
		count2--;
		count1++;
	}
	for (int i = 0;i < n;i++)
		printf("%c", x[i]);
	printf("\n");
	return 0;
}
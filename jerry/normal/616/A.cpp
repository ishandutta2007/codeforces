#include <bits/stdc++.h>
using namespace std;

char a[1000005], b[1000005]; int x, y;

int main()
{
	scanf("%s%s", a, b);
	for (;a[x];x++); reverse(a, a+x);
	for (;b[y];y++); reverse(b, b+y);
	while (x && a[--x]=='0'); x++;
	while (y && b[--y]=='0'); y++;
	if (x < y) printf("<\n");
	else if (x > y) printf(">\n");
	else
	{
		while (x && a[--x] == b[--y]);
		if (a[x] < b[y]) printf("<\n");
		else if (a[x] > b[y]) printf(">\n");
		else printf("=\n");
	}
	return 0;
}
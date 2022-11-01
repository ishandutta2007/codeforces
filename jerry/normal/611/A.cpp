#include <bits/stdc++.h>
using namespace std;

int wk[] = {0, 52, 52, 52, 52, 53, 53, 52};
int a; char buf[16];

int main()
{
	scanf("%d%s", &a, buf); scanf("%s", buf);
	if (buf[0] == 'w') printf("%d\n", wk[a]);
	else
	{
		if (a <= 29) printf("12\n");
		else if (a == 30) printf("11\n");
		else if (a >= 31) printf("7\n");
	}
	return 0;
}
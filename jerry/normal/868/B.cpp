#include <bits/stdc++.h>
using namespace std;

int a[5], x, y;

void yer()
{
	printf("YES\n");
	exit(0);
}

int main()
{
	cin >> a[0] >> a[1] >> a[2] >> x >> y;
	if (a[0] == 12) a[0] = 0;
	if (x == 12) x = 0;
	if (y == 12) y = 0;
	a[0] *= 3600; a[1] *= 3600; a[2] *= 3600;
	a[1] += a[2] / 60;
	a[0] += a[1] / 60;
	a[0] *= 5;
	x *= 3600*5; y *= 3600*5;
	if (x > y) swap(x, y);
	//printf("%d %d %d %d %d\n", a[0], a[1], a[2], x, y);

	sort(a, a+3);
	if (a[0] < x && y < a[1]) yer();
	if (a[1] < x && y < a[2]) yer();
	if (x < a[0] && y > a[2]) yer();
	if (y < a[0]) yer();
	if (x > a[2]) yer();
	printf("NO\n");
	return 0;
}
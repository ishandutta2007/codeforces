#include <bits/stdc++.h>
using namespace std;

#define x1 asdfasdf
#define x2 asdfasdfasdf
#define y1 asdfasdfasdfasdf
#define y2 asdfasdfasdfasdfasdf

int x[1005], y[1005], n;

int getang(int i)
{
	int x1 = x[i+1] - x[i  ], y1 = y[i+1] - y[i  ];
	int x2 = x[i+2] - x[i+1], y2 = y[i+2] - y[i+1];
	int val = x1*y2 - x2*y1;
	assert(val != 0);
	if (val > 0) return 1;
	return -1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i <= n;i++) scanf("%d%d", x+i, y+i);
	x[n+1] = x[1], y[n+1] = y[1];
	int t = 0;
	for (int i = 0;i < n;i++) t += getang(i);
	assert(t == 4 || t == -4);
	t /= 4;
	int ans = 0;
	for (int i = 0;i < n;i++) if (getang(i) != t)
		ans++;
	printf("%d\n", ans);
	return 0;
}
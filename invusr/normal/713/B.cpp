#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n;

inline int query(int x1, int x2, int y1, int y2)
{
	printf("? ");
	printf("%d %d%c", x1, y1, ' ');
	printf("%d %d%c", x2, y2, '\n');
	fflush(stdout);

	int num;
	scanf("%d", &num);
	return num;
}

inline bool solve1()
{
	int vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(1, mid, 1, n) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int r1 = vl;

	vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(mid, n, 1, n) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	if (vr <= r1)
		return false;
	int l2 = vr;

	vl = 1, vr = r1;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(mid, r1, 1, n) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	int l1 = vr;

	vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(l1, r1, mid, n) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	int u1 = vr;

	vl = u1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(l1, r1, u1, mid) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int d1 = vl;

	vl = l2, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(l2, mid, 1, n) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int r2 = vl;

	vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(l2, r2, mid, n) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	int u2 = vr;

	vl = u2, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(l2, r2, u2, mid) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int d2 = vl;

	printf("! ");
	printf("%d %d %d %d%c", l1, u1, r1, d1, ' ');
	printf("%d %d %d %d%c", l2, u2, r2, d2, '\n');
	return true;
}

inline void solve2()
{
	int vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(1, n, 1, mid) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int d1 = vl;

	vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(1, n, mid, n) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	int u2 = vr;

	vl = 1, vr = d1;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(1, n, mid, d1) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	int u1 = vr;

	vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(1, mid, u1, d1) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int r1 = vl;

	vl = 1, vr = r1;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(mid, r1, u1, d1) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	int l1 = vr;

	vl = u2, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(1, n, u2, mid) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int d2 = vl;

	vl = 1, vr = n;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(1, mid, u2, d2) == 0)
			vl = mid + 1;
		else
			vr = mid - 1;
	}
	int r2 = vl;

	vl = 1, vr = r2;
	while (vl <= vr)
	{
		int mid = vl + vr >> 1;
		if (query(mid, r2, u2, d2) == 0)
			vr = mid - 1;
		else
			vl = mid + 1;
	}
	int l2 = vr;

	printf("! ");
	printf("%d %d %d %d%c", l1, u1, r1, d1, ' ');
	printf("%d %d %d %d%c", l2, u2, r2, d2, '\n');
}

int main()
{
	scanf("%d", &n);

	if (!solve1())
		solve2();

	return 0;
}
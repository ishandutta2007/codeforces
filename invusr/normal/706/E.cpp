#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1001;
const int MaxTN = MaxN * MaxN;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int n, m, q;
int val[MaxN][MaxN];

struct point
{
	int x, y;

	point() {}
	point(int _x, int _y)
		: x(_x), y(_y) {}
};

const point ori = point(0, 0);

point to[MaxN][MaxN][2]; // 0: right; 1: down;

inline point move_to(point x, int xl, int yl)
{
	while (yl--)
		x = to[x.x][x.y][0];
	while (xl--)
		x = to[x.x][x.y][1];
	return x;
}

inline void print()
{
	for (int i = 1; i <= n; ++i)
	{
		point p = move_to(ori, i, 0);
		for (int j = 0; j < m; ++j)
		{
			p = move_to(p, 0, 1);
			printf("%d ", val[p.x][p.y]);
		}
		puts("");
	}
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			val[i][j] = getint();
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
		{
			to[i][j][0] = point(i, j + 1);
			to[i][j][1] = point(i + 1, j);
		}

	while (q--)
	{
		int x0 = getint(), y0 = getint();
		int x1 = getint(), y1 = getint();
		int h = getint(), w = getint();

		point d0 = move_to(ori, x0, y0 - 1);
		point d1 = move_to(ori, x1, y1 - 1);
		point d2 = move_to(ori, x0, y0 + w - 1);
		point d3 = move_to(ori, x1, y1 + w - 1);
		point d4 = move_to(ori, x0 - 1, y0);
		point d5 = move_to(ori, x1 - 1, y1);
		point d6 = move_to(ori, x0 + h - 1, y0);
		point d7 = move_to(ori, x1 + h - 1, y1);
		for (int i = 0; i < h; ++i)
		{
			swap(to[d0.x][d0.y][0], to[d1.x][d1.y][0]);
			d0 = move_to(d0, 1, 0);
			d1 = move_to(d1, 1, 0);
		}

		d0 = d2, d1 = d3;
		for (int i = 0; i < h; ++i)
		{
			swap(to[d0.x][d0.y][0], to[d1.x][d1.y][0]);
			d0 = move_to(d0, 1, 0);
			d1 = move_to(d1, 1, 0);
		}

		d0 = d4, d1 = d5;
		for (int i = 0; i < w; ++i)
		{
			swap(to[d0.x][d0.y][1], to[d1.x][d1.y][1]);
			d0 = move_to(d0, 0, 1);
			d1 = move_to(d1, 0, 1);
		}

		d0 = d6, d1 = d7;
		for (int i = 0; i < w; ++i)
		{
			swap(to[d0.x][d0.y][1], to[d1.x][d1.y][1]);
			d0 = move_to(d0, 0, 1);
			d1 = move_to(d1, 0, 1);
		}
	}

	print();

	return 0;
}
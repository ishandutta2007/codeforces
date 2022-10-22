#include <bits/stdc++.h>

using namespace std;

int query(long long x, long long y)
{
	printf("%lld %lld\n", x, y);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	if (ans == 0)
		exit(0);
	return ans;
}

namespace jumpmelon
{
	typedef long double ld;
	typedef long long big;

	const int MAXM = 250;
	int m;
	big lx, ly;
	struct point
	{
		big x, y;
	} V[MAXM + 2];

	inline bool operator<(const point &a, const point b) { return a.x < b.x; }

	ld get_s()
	{
		ld s = 0;
		for (int i = 0; i + 1 < m; i++)
			s += ld(V[i + 1].x - V[i].x) * (V[i].y - ly);
		return s;
	}

	big get_x(ld s)
	{
		for (int i = 0; i + 1 < m; i++)
		{
			ld t = ld(V[i + 1].x - V[i].x) * (V[i].y - ly);
			if (t && s <= t)
				return V[i].x + big(s / (V[i].y - ly)) + 1;
			s -= t;
		}
		throw;
	}

	big get_y(ld s)
	{
		for (int i = m - 1; i >= 1; i--)
		{
			ld t = ld(V[i - 1].y - V[i].y) * (V[i].x - lx);
			if (t && s <= t)
				return V[i].y + big(s / (V[i].x - lx)) + 1;
			s -= t;
		}
		throw;
	}

	void update()
	{
		int t = 0;
		for (int i = 0; i < m; i++)
		{
			point p = {max(lx, V[i].x), max(ly, V[i].y)};
			if (t == 0 || p.y < V[t - 1].y)
				V[t++] = p;
		}
		m = t;
	}

	void play(big nx, big ny)
	{
		lx = ly = 0;
		V[m++] = {0, ny};
		V[m++] = {nx, 0};
		while (1)
		{
			ld s = get_s();
			big x = get_x(s / 3);
			big y = get_y(s / 3);
			int ans = query(x, y);
			if (ans == 1)
				lx = x;
			else if (ans == 2)
				ly = y;
			else
			{
				point p = {x - 1, y - 1};
				int i = int(lower_bound(V, V + m, p) - V);
				memmove(V + i + 1, V + i, sizeof(point[m - i]));
				V[i] = p;
				m++;
			}
			update();
		}
	}
}

void play(long long nx, long long ny, int) { jumpmelon::play(nx, ny); }

int main()
{
	long long n;
	scanf("%lld", &n);
	play(n, n, 600);
	return 0;
}
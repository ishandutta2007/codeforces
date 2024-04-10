#include <bits/stdc++.h>

using namespace std;
mt19937 s(chrono::steady_clock::now().time_since_epoch().count() ^ 19260817);

inline int rnd(int l, int r)
{
	return uniform_int_distribution<int>(l, r)(s);
}



int query(int x, int y)
{
	cout << "? " << x << " " << y << endl;
	cout.flush();
	int t;
	cin >> t;
	return t;
}

int main()
{
	int n, m;
	int d1 = query(1, 1), d2 = query(1, 1e9), d3 = query(1e9, 1);
	int dx = -1, dy = -1;
	int lx = 1, rx = 1e9;
	if (d1 > d2)
	{
		lx += d1 - d2;
	}
	else if (d2 > d1)
	{
		rx -= d2 - d1;
	}
	int midx = lx + rx >> 1;
	dy = query(1, midx);
	int ly = 1, ry = 1e9;
	if (d1 > d3)
	{
		ly += d1 - d3;
	}
	else if (d3 > d1)
	{
		ry -= d3 - d1;
	}
	int midy = ly + ry >> 1;
	dx = query(midy, 1);
	int a1 = dy + 1, b1 = dx + 1, a2 = 1e9 - (d2 - dy), b2 = 1e9 - (d3 - dx);
	
	//printf("dx = %d, dy = %d, d1 = %d, d2 = %d, d3 = %d\n", dx, dy, d1, d2, d3);
	cout << "! " << a1 << " " << b1 << " " << b2 << " " << a2 << endl;
	
}
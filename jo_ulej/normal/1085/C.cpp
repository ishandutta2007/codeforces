#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = 1e7 + 9;

bool grid[1001][1001];

int dist(int x1, int x2, int y1, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

void go(int x1, int x2, int y1, int y2)
{
	grid[x1][y1] = true;
	grid[x2][y2] = true;

	while(x1 != x2)
	{
		if(x1 < x2)
			++x1;
		else
			--x1;

		grid[x1][y1] = true;
	}

	while(y1 != y2)
	{
		if(y1 < y2)
			++y1;
		else
			--y1;

		grid[x1][y1] = true;
	}
}

void solve()
{
	int x[3], y[3];

	for(int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];

	int bx, by, bd = INT_INF;

	for(int nx = 0; nx <= 1100; ++nx)
	{
		for(int ny = 0; ny <= 1100; ++ny)
		{
			int b = dist(x[0], nx, y[0], ny) + dist(x[1], nx, y[1], ny) + dist(x[2], nx, y[2], ny);

			if(b < bd)
				bd = b, bx = nx, by = ny;
		}
	}

	for(int i = 0; i < 3; ++i)
		go(x[i], bx, y[i], by);

	cout << bd + 1 << "\n";

	for(int i = 0; i <= 1000; ++i)
		for(int j = 0; j <= 1000; ++j)
			if(grid[i][j])
				cout << i << " " << j << "\n";
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}
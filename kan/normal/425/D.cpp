#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxx = 100005;

set<pair<int, int> > points;

typedef set<pair<int, int> >::iterator siter;

vector<int> on_x[maxx], on_y[maxx];
unordered_set<int> on_x_u[maxx];
int n;
int answer;

inline bool exists(int x, int y)
{
	if (x < 0 || x >= maxx) return false;
	return on_x_u[x].count(y);
}

inline void checkx(int x, int y1, int y2)
{
	int d = abs(y1 - y2);
	if (exists(x - d, y1) && exists(x - d, y2)) answer++;
	if (exists(x + d, y1) && exists(x + d, y2)) answer++;
}

inline void checky(int y, int x1, int x2)
{
	int d = abs(x1 - x2);
	if (exists(x1, y - d) && exists(x2, y - d)) answer++;
	if (exists(x1, y + d) && exists(x2, y + d)) answer++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		on_x[x].push_back(y);
		on_x_u[x].insert(y);
		on_y[y].push_back(x);
		points.insert(make_pair(x, y));
	}
	answer = 0;
	for (siter it = points.begin(); it != points.end(); it++)
	{
		int x = it->first;
		int y = it->second;
		int kvx = on_x[x].size();
		int kvy = on_y[y].size();
		if (kvx < kvy)
		{
			for (int i = 0; i < (int)on_x[x].size(); i++) if (on_x[x][i] != y) checkx(x, y, on_x[x][i]);
		} else
		{
			for (int i = 0; i < (int)on_y[y].size(); i++) if (on_y[y][i] != x) checky(y, x, on_y[y][i]);
		}
	}
	cout << answer / 4 << endl;
	return 0;
}
#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <complex>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cout << #x << " : " << (x) << endl
#define print_array(arr, len) {cout << #arr << " : "; for(int i = 0; i < len; ++i) cout << arr[i] << ' '; cout << endl;}
#define print_2d_array(arr, len1, len2) {cout << #arr << endl; for(int i = 0; i < len1; ++i, cout << endl) for(int j = 0; j < len2; ++j) cout << arr[i][j] << ' ';}
#define print_iterable(i) {cout << #i << " : "; for(auto e : i) cout << e << ' '; cout << endl;}
#define print_new_line() cout << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) {}
#define print_2d_array(arr, len1, len2) {}
#define print_iterable(i) {}
#define print_new_line() (void)0
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-7;
const ld EPS = 1e-11;

#pragma endregion

struct Point
{
	int x, y;
	Point() : x(), y() {}
	Point(int x, int y) : x(x), y(y) {}
	Point operator+ (const Point& p) const
	{
		return Point(x + p.x, y + p.y);
	}
	bool operator< (const Point& p) const
	{
		if (x != p.x)
			return x < p.x;
		return y < p.y;
	}
	ll geth()
	{
		return x * (ll) INF + y;
	}
};
typedef pair<Point, Point> ppp;

Point dirs[3][3];
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
set<ppp> vects;
unordered_set<ll> used;

void solve()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			dirs[i][j] = Point(i - 1, j - 1);
	int n;
	scanf("%d", &n);
	vects.emplace(Point(0, 0), Point(0, 1));
	used.insert(Point(0, 0).geth());
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		set<ppp> nvects;
		while (--t)
		{
			for(auto pp : vects)
			{
				auto pos = pp.first;
				auto dir = pp.second;
				auto npos = pos + dir;
				used.insert(npos.geth());
				nvects.emplace(npos, dir);
			}
			vects = nvects;
			nvects.clear();
		}
		if (i == n - 1)
			break;
		for(auto pp : vects)
		{
			auto pos = pp.first;
			auto dir = pp.second;
			int i = dir.x + 1;
			int j = dir.y + 1;
			for (int d = 0; d < 4; ++d)
			{
				int ni = i + di[d];
				int nj = j + dj[d];
				if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3 && !(ni == 1 && nj == 1))
				{
					auto ndir = dirs[ni][nj];
					auto npos = pos + ndir;
					nvects.emplace(npos , ndir);
					used.insert(npos.geth());
				}
			}
		}
		vects = nvects;
		nvects.clear();
	}
	//for (int i = 40; i > -40; --i, puts(""))
	//	for (int j = -40; j < 40; ++j)
	//		printf(used.count(Point(j, i).geth()) ? "X" : ".");
	printf("%d\n", used.size());
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef ST
	while (true)
	{
		solve();
	}
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}
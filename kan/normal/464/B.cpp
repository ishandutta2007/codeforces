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

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int n = 8;

struct pt
{
	int x, y, z;
	pt() {}
	pt(int x, int y, int z): x(x), y(y), z(z) {}
};

inline pt operator-(const pt &a, const pt &b)
{
	return pt(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline pt operator+(const pt &a, const pt &b)
{
	return pt(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline ll operator/(const pt &a, const pt &b)
{
	return (ll)a.x * b.x + (ll)a.y * b.y + (ll)a.z * b.z;
}

pt p[10], v[10];
bool used[10];

bool matches(int cur, pt wh)
{
	int crd[3];
	crd[0] = p[cur].x;
	crd[1] = p[cur].y;
	crd[2] = p[cur].z;
	sort(crd, crd + 3);
	do
	{
		if (crd[0] == wh.x && crd[1] == wh.y && crd[2] == wh.z)
		{
			p[cur].x = crd[0];
			p[cur].y = crd[1];
			p[cur].z = crd[2];
			return true;
		}
	} while (next_permutation(crd, crd + 3));
	return false;
}

void check()
{
	if (v[0].x == 0 && v[0].y == 0 && v[0].z == 0) return;
	fill(used, used + n, false);
// 	if (v[0].x != 0 || v[0].y != 0 || v[0].z != 1) return;
// 	if (v[1].x != 0 || v[1].y != 1 || v[1].z != 0) return;
// 	cout << "check " << endl;
	v[3] = v[0];
	for (int i = 0; i < 3; i++) if (v[i] / v[i + 1] != 0 || v[i] / v[i] != v[i + 1] / v[i + 1]) return;
	for (int mask = 1; mask < n; mask++)
	{
		bool found = false;
		pt wh = p[0];
		for (int i = 0; i < 3; i++) if (mask & (1 << i)) wh = wh + v[i];
		for (int i = 1; i < n; i++) if (!used[i] && matches(i, wh))
		{
			found = true;
			used[i] = true;
			break;
		}
		if (!found) return;
	}
// 	cout << "found" << endl;
	printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d %d %d\n", p[i].x, p[i].y, p[i].z);
	}
	exit(0);
}

void go(int cur, int curk)
{
// 	cout << "go " << cur << ' ' << curk << endl;
	if (cur == n)
	{
		if (curk == 3) check();
		return;
	}
	go(cur + 1, curk);
	int crd[3];
	crd[0] = p[cur].x;
	crd[1] = p[cur].y;
	crd[2] = p[cur].z;
	sort(crd, crd + 3);
// 	printf("%d %d %d\n", p[cur].x, p[cur].y, p[cur].z);
// 	printf("%d %d %d\n", p[0].x, p[0].y, p[0].z);
	do
	{
		v[curk] = pt(crd[0], crd[1], crd[2]) - p[0];
// 		if (curk == 1 && cur == 2) cout << "go2 " << v[curk].x << ' ' << v[curk].y << ' ' << v[curk].z << endl;
		go(cur + 1, curk + 1);
	} while (next_permutation(crd, crd + 3));
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
	}
	go(1, 0);
	printf("NO\n");
	return 0;
}
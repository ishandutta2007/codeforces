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

struct pt
{
	int x, y;
	pt() {}
	pt(int x, int y): x(x), y(y) {}
};

inline pt operator-(const pt &a, const pt &b)
{
	return pt(a.x - b.x, a.y - b.y);
}

inline ll operator*(const pt &a, const pt &b)
{
	return (ll)a.x * b.y - (ll)a.y * b.x;
}

inline ll operator/(const pt &a, const pt &b)
{
	return (ll)a.x * b.x + (ll)a.y * b.y;
}

inline int sgn(ll a)
{
	if (a < 0) return -1;
	if (a > 0) return 1;
	return 0;
}

inline bool on(pt a, pt b, pt c)
{
	return (c - a) * (b - a) == 0 && (a - c) / (b - c) < 0;
}

inline bool intersect(pt a, pt b, pt c, pt d)
{
	if (on(a, b, c) || on(a, b, d) || on(c, d, a) || on(c, d, b)) return true;
	int s1 = sgn((c - a) * (b - a)) * sgn((d - a) * (b - a));
	int s2 = sgn((a - c) * (d - c)) * sgn((b - c) * (d - c));
	return s1 < 0 && s2 < 0;
}

inline bool between(pt a, pt b, pt c)
{
	ld aa = atan2(a.y, a.x);
	ld ab = atan2(b.y, b.x);
	ld ac = atan2(c.y, c.x);
	while (ab < aa) ab += 2 * M_PI;
	while (ac < aa) ac += 2 * M_PI;
	return ac < ab;
}

const int maxn = 205;
const int MOD = 1000000007;

pt p[maxn];
ll kv[maxn][maxn];
bool can[maxn][maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	p[n] = p[0];
	ll sq = 0;
	for (int i = 0; i < n; i++) sq += p[i] * p[i + 1];
	if (sq < 0)
	{
// 		cout << "inverse" << endl;
		reverse(p, p + n);
		p[n] = p[0];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 2; j < n; j++)
		{
			can[i][j] = true;
			for (int t = 0; t < n; t++) if (intersect(p[i], p[j], p[t], p[t + 1])) can[i][j] = false;
			for (int t = 0; t < n; t++) if (on(p[i], p[j], p[t])) can[i][j] = false;
			if (!between(p[j + 1] - p[j], p[j - 1] - p[j], p[i] - p[j])) can[i][j] = false;
			can[j][i] = can[i][j];
		}
	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < n; j++) cout << "can " << i << ' ' << j << ' ' << can[i][j] << endl;
// 	}
	for (int i = 0; i < n; i++)
	{
		kv[i][(i + 1) % n] = 1;
	}
	for (int len = 2; len <= n - 1; len++)
	{
		for (int i = 0; i < n; i++)
		{
			int j = (i + len) % n;
			kv[i][j] = 0;
			if (len < n - 1 && !can[i][j]) continue;
			for (int t = 1; t < len; t++) kv[i][j] = (kv[i][j] + kv[i][(i + t) % n] * kv[(i + t) % n][j]) % MOD;
// 			cout << i << ' ' << j << ' ' << kv[i][j] << endl;
		}
	}
	cout << kv[0][n - 1] << endl;
	return 0;
}
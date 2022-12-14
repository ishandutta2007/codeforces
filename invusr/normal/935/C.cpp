#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

typedef double r32;
typedef long double r64;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

const r32 eps = 1e-7;

struct point
{
	r32 x, y;
	point() {}
	point(const r32 &_x, const r32 &_y)
		: x(_x), y(_y) {}

	inline r32 norm() const
	{
		return sqrt(x * x + y * y);
	}

	friend inline point operator+(const point &lhs, const point &rhs)
	{
		return point(lhs.x + rhs.x, lhs.y + rhs.y);
	}
	friend inline point operator-(const point &lhs, const point &rhs)
	{
		return point(lhs.x - rhs.x, lhs.y - rhs.y);
	}
	friend inline point operator*(const point &lhs, const r32 &rhs)
	{
		return point(lhs.x * rhs, lhs.y * rhs);
	}
	friend inline point operator/(const point &lhs, const r32 &rhs)
	{
		return point(lhs.x / rhs, lhs.y / rhs);
	}

	friend inline r32 operator*(const point &lhs, const point &rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}
};

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	int r;
	int x1, y1, x2, y2;

	cin >> r;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 == x2 && y1 == y2)
	{
		printf("%.16f %.16f ", (r32)x1, (r32)y1 + 0.5 * r);
		printf("%.16f\n", 0.5 * r);
		return 0;
	}

	int dx = x1 - x2;
	int dy = y1 - y2;
	s64 d = ((s64)dx * dx + (s64)dy * dy);

	if (d >= (s64)r * r)
	{
		printf("%d %d ", x1, y1);
		printf("%d\n", r);
		return 0;
	}

	point p1(x1, y1);
	point p2(x2, y2);
	point dir = p1 - p2;

	r32 l = dir.norm();
	r32 a = l + r;
	dir = dir / l * (a * 0.5);

	point k = p2 + dir;

	printf("%.16f %.16f ", k.x, k.y);
	printf("%.16f\n", a * 0.5);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
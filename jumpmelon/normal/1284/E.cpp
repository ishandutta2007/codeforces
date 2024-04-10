#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long double ld;

	typedef long long big;

	struct vector2
	{
		int x, y;
		ld angle() const { return atan2((ld)y, (ld)x); }
	};

	inline bool operator <(const vector2 &a, const vector2 &b) { return a.angle() < b.angle(); }
	inline vector2 operator -(const vector2 &A, const vector2 &B) { return {A.x - B.x, A.y - B.y}; }
	inline big cross(const vector2 &A, const vector2 &B) { return (big)A.x * B.y - (big)A.y * B.x; }

	const int MAXN = 2500;
	const ld PI = acos(-1.0L);
	int n;
	big F[MAXN + 1];

	vector2 V[MAXN];
	ld A[MAXN << 1];

	vector<int> get(int a, int b, int c, int d)
	{
		vector<int> X = {a, b, c, d};
		for (int i = 0; i < 4; i++)
			if (X[i] >= n - 1)
				X[i] -= n - 1;
		sort(X.begin(), X.end());
		return X;
	}

	big solve(int p)
	{
		int m = 0;
		for (int i = 0; i < n; i++)
			if (i != p)
				A[m++] = (V[i] - V[p]).angle();
		sort(A, A + m);
		for (int i = 0; i < m; i++)
			A[i + m] = A[i] + 2 * PI;
		big ans = (big)m * (m - 1) * (m - 2) * (m - 3) / 24;
		for (int i = 0, j = 0; i < m; i++)
		{
			while (j + 1 < (m << 1) && A[j + 1] - A[i] < PI)
				j++;
			ans -= F[j - i + 1];
		}
		return ans;
	}

	void work()
	{
		big ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &V[i].x, &V[i].y);
		for (int i = 4; i <= n; i++)
			F[i] = F[i - 1] + (big)(i - 2) * (i - 3) / 2;
		for (int i = 0; i < n; i++)
			ans += solve(i);
		printf("%lld\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}
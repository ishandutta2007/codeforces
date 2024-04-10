#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 100000, P = 1000000007;
	int n, A[MAXN + 1], L[MAXN + 1], R[MAXN + 1];
	int St[MAXN + 1], BL[MAXN + 1], BR[MAXN + 1];

#define lt (p << 1)
#define rt (p << 1 | 1)

	struct seg_tree
	{
	private:
		struct node
		{
			int cov, sum;
		} T[(MAXN << 2) + 10];

		void update_p(int v, int p, int a, int b)
		{
			T[p].cov = v;
			T[p].sum = int(big(b - a + 1) * v % P);
		}
		void push_down(int p, int a, int b)
		{
			if (T[p].cov != -1)
			{
				int mid = (a + b) >> 1;
				update_p(T[p].cov, lt, a, mid);
				update_p(T[p].cov, rt, mid + 1, b);
				T[p].cov = -1;
			}
		}
		void maintain(int p) { T[p].sum = (T[lt].sum + T[rt].sum) % P; }

	public:
		void update(int x, int y, int v, int p = 1, int a = 1, int b = n);
		int query(int x, int y, int p = 1, int a = 1, int b = n);
		int query(int x) { return query(x, x); }
	};

	void seg_tree::update(int x, int y, int v, int p, int a, int b)
	{
		if (x <= a && b <= y)
			update_p(v, p, a, b);
		else
		{
			push_down(p, a, b);
			int mid = (a + b) >> 1;
			if (x <= mid)
				update(x, y, v, lt, a, mid);
			if (y > mid)
				update(x, y, v, rt, mid + 1, b);
			maintain(p);
		}
	}

	int seg_tree::query(int x, int y, int p, int a, int b)
	{
		if (T[p].cov != -1)
			return int(big(y - x + 1) * T[p].cov % P);
		else if (x == a && b == y)
			return T[p].sum;
		else
		{
			int mid = (a + b) >> 1;
			if (y <= mid)
				return query(x, y, lt, a, mid);
			else if (x > mid)
				return query(x, y, rt, mid + 1, b);
			else
				return (query(x, mid, lt, a, mid) + query(mid + 1, y, rt, mid + 1, b)) % P;
		}
	}

#undef lt
#undef rt

	seg_tree TL, TR;

	inline int sum(int x) { return int((big)x * (x + 1) / 2 % P); }
	inline int sum(int x, int y) { return (sum(y) + P - sum(x - 1)) % P; }

	void work()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		map<int, int> Pos;
		for (int i = 1; i <= n; i++)
		{
			L[i] = Pos.count(A[i]) ? Pos[A[i]] + 1 : 1;
			Pos[A[i]] = i;
		}
		Pos.clear();
		for (int i = n; i >= 1; i--)
		{
			R[i] = Pos.count(A[i]) ? Pos[A[i]] - 1 : n;
			Pos[A[i]] = i;
		}
		Pos.clear();
		int *top = St;
		*top = n + 1;
		for (int i = n; i >= 1; i--)
		{
			while (top > St && L[*top] <= L[i])
				top--;
			BL[i] = *top - 1;
			*++top = i;
		}
		top = St;
		for (int i = n; i >= 1; i--)
		{
			while (top > St && R[*top] >= R[i])
				top--;
			BR[i] = *top - 1;
			*++top = i;
		}
		int s1 = 0, s2 = 0, ans = 0;
		for (int i = n, m = n; i >= 1; i--)
		{
			for (int j = i + 1; j <= BL[i]; j = BL[j] + 1)
			{
				s1 = int((s1 + big(P - L[j]) * sum(j, BL[j])) % P);
				s2 = int((s2 + big(P - L[j]) * TR.query(j, BL[j])) % P);
			}
			TL.update(i, BL[i], L[i]);
			s1 = int((s1 + (big)L[i] * sum(i, BL[i])) % P);
			s2 = int((s2 + (big)L[i] * TR.query(i, BL[i])) % P);
			for (int j = i + 1; j <= m && j <= BR[i]; j = BR[j] + 1)
				s2 = int((s2 + big(P - R[j]) * TL.query(j, min(m, BR[j]))) % P);
			TR.update(i, BR[i], R[i]);
			s2 = int((s2 + (big)R[i] * TL.query(i, min(m, BR[i]))) % P);
			while (TL.query(m) > i || TR.query(m) < m)
			{
				s1 = int((s1 + big(P - TL.query(m)) * m) % P);
				s2 = int((s2 + big(P - TL.query(m)) * TR.query(m)) % P);
				m--;
			}
			ans = int((ans + (big)i * TR.query(i, m) + big(P - i) * sum(i, m) + s1 + P - s2) % P);
		}
		printf("%d\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}
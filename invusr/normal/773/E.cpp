#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

typedef pair<int, int> seg_info;

const int MaxN = 500005;
const int MaxSegN = MaxN * 4;

int n;
int pos[MaxN];
seg_info a[MaxN];

seg_info seg[MaxSegN];
int delta[MaxSegN];

inline void seg_update(int p)
{
	seg[p] = min(seg[p << 1 | 0], seg[p << 1 | 1]);
}

inline void seg_tag_add(int p, int d)
{
	delta[p] += d;
	seg[p].first += d;
}
inline void seg_tag_down(int p)
{
	if (delta[p])
	{
		int d = delta[p];
		seg_tag_add(p << 1 | 0, d);
		seg_tag_add(p << 1 | 1, d);
		delta[p] = 0;
	}
}

void seg_build(int p, int pL, int pR)
{
	if (pL == pR)
		seg[p] = make_pair(a[pL].first, pL);
	else
	{
		int pM = pL + pR >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_update(p);
	}
}
void seg_add(int p, int pL, int pR, int qL, int qR, int d)
{
	if (qL <= pL && qR >= pR)
	{
		seg_tag_add(p, d);
		return;
	}

	seg_tag_down(p);

	int pM = pL + pR >> 1;
	if (qL <= pM)
		seg_add(p << 1 | 0, pL, pM, qL, qR, d);
	if (qR > pM)
		seg_add(p << 1 | 1, pM + 1, pR, qL, qR, d);

	seg_update(p);
}
seg_info seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL == pL && qR == pR)
		return seg[p];

	seg_tag_down(p);

	int pM = pL + pR >> 1;
	if (qR <= pM)
		return seg_query(p << 1 | 0, pL, pM, qL, qR);
	else if (qL > pM)
		return seg_query(p << 1 | 1, pM + 1, pR, qL, qR);
	else
	{
		seg_info l = seg_query(p << 1 | 0, pL, pM, qL, pM);
		seg_info r = seg_query(p << 1 | 1, pM + 1, pR, pM + 1, qR);
		return min(l, r);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		pos[a[i].second] = i;

	seg_build(1, 1, n);

	set<int> minus, zero, plus;
	for (int k = 1; k <= n; ++k)
	{
		int i = pos[k];
		seg_info p = seg_query(1, 1, n, i, i);

		if (p.first == 0)
			zero.insert(i);
		else if (p.first > 0)
		{
			plus.insert(i);

			seg_info q = seg_query(1, 1, n, i, n);
			if (q.first > 0)
				seg_add(1, 1, n, i, n, -1);
			else
			{
				plus.erase(q.second);
				zero.insert(q.second);
				if (q.second > i)
					seg_add(1, 1, n, i, q.second - 1, -1);
			}
		}
		else
		{
			minus.insert(i);

			int last = *--minus.end();
			if (a[last].first == 1 - minus.size())
			{
				minus.erase(last);
				zero.insert(last);
				if (last > i)
					seg_add(1, 1, n, i, last - 1, 1);
			}
			else if (!zero.empty())
			{
				last = *zero.begin();
				zero.erase(last);
				plus.insert(last);
				if (last > i)
					seg_add(1, 1, n, i, last - 1, 1);
			}
			else
				seg_add(1, 1, n, i, n, 1);
		}

		printf("%d\n", plus.size() - minus.size());
	}

	return 0;
}
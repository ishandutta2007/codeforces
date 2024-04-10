#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');

	if (c != '-')
	{
		int res = c - '0';
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
	else
	{
		int res = 0;
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
}

const int MaxN = 100005;
const int MaxTN = 262155;

int n;
int op[MaxN], lhs[MaxN], rhs[MaxN];

int m = 0;
int bl[MaxN], br[MaxN];

int li_n = 0;
int li[MaxN * 2];

int ufs[MaxN];

int ufs_find(const int &v)
{
	return ufs[v] ? ufs[v] = ufs_find(ufs[v]) : v;
}

int offset;
vector<int> pos[MaxTN * 2 + 1];

inline void update_range(int p, int v)
{
	for (p += offset; p; p >>= 1)
	{
		while (!pos[p].empty())
		{
			int u = pos[p].back();
			pos[p].pop_back();
			bl[v] = min(bl[v], bl[u]);
			br[v] = max(br[v], br[u]);
			ufs[u] = v;
		}
	}
}
inline void insert(int l, int r, int v)
{
	for (l += offset, r += offset; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if (~l & 1)
			pos[l ^ 1].push_back(v);
		if (r & 1)
			pos[r ^ 1].push_back(v);
	}
}

int main()
{
	n = getint();
	for (int i = 0; i < n; ++i)
	{
		op[i] = getint();
		lhs[i] = getint(), rhs[i] = getint();
		if (op[i] == 1)
		{
			li[++li_n] = lhs[i];
			li[++li_n] = rhs[i];
		}
	}

	sort(li + 1, li + li_n + 1);
	li_n = unique(li + 1, li + li_n + 1) - li - 1;

	offset = 1;
	while (offset < li_n)
		offset <<= 1;

	for (int i = 0; i < n; ++i)
	{
		if (op[i] == 1)
		{
			ufs[++m] = 0;
			bl[m] = lhs[i] = lower_bound(li + 1, li + li_n + 1, lhs[i]) - li;
			br[m] = rhs[i] = lower_bound(li + 1, li + li_n + 1, rhs[i]) - li;
			update_range(lhs[i], m);
			update_range(rhs[i], m);
			insert(bl[m], br[m], m);
		}
		else
		{
			int u = ufs_find(lhs[i]);
			int v = ufs_find(rhs[i]);
			if (bl[u] >= bl[v] && br[u] <= br[v])
				puts("YES");
			else
				puts("NO");
		}
	}

	return 0;
}
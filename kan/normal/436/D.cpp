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

#define left left_sdf
#define right right_sdf

const int maxn = 100005;
const int maxm = 2005;
const int inf = 1e9;

int x[maxn];
int stx[maxm];
int ans[maxn], stop[maxn];
int left[maxn], right[maxn];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 0; i < m; i++) scanf("%d", &stx[i]);
	sort(x, x + n);
	sort(stx, stx + m);
	left[0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (x[i] - 1 == x[i - 1]) left[i] = left[i - 1];
		else left[i] = i;
	}
	right[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if (x[i] + 1 == x[i + 1]) right[i] = right[i + 1];
		else right[i] = i;
	}
// 	for (int i = 0; i < m; i++) wh[i] = lower_bound(x, x + n, stx[i]) - x;
	
	stx[m] = inf;
	ans[0] = 0;
	for (int i = 0; i < n; i++)
	{
// 		cout << "i = " << i << endl;
		int starr = lower_bound(stx, stx + m, x[i]) - stx;
		bool onstar = stx[starr] == x[i];
		stop[i] = ans[i] + onstar;
		for (int j = 0; j < starr; j++)
		{
			int need = x[i] - stx[j];
			if (i >= need) stop[i] = max(stop[i], starr - j + ans[left[i - need]] + onstar);
		}
// 		cout << "stop = " << stop[i] << endl;
		ans[i + 1] = max(ans[i + 1], stop[i]);
		if (onstar) starr++;
		for (int j = starr; j < m; j++)
		{
			int need = stx[j] - x[i];
			if (n - i - 1 >= need)
			{
				ans[right[i + need] + 1] = max(ans[right[i + need] + 1], j - starr + 1 + stop[i]);
// 				cout << "upd " << right[i + need] + 1 << ' ' << j - starr + 1 + stop[i] << endl;
			}
		}
	}
	cout << ans[n] << endl;
	return 0;
}
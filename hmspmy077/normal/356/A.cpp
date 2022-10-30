#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

const int N = 500005;

int f[N], ans[N];

int find(int i)
{
	if (f[i] != i) f[i] = find(f[i]);
	return f[i];
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
//		freopen("c.out","w",stdout);
	#endif
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n + 1; ++i) f[i] = i;
	for (int gxx = 1; gxx <= q; ++gxx)
	{
		int l, r, win;
		scanf("%d%d%d", &l, &r, &win);
		for (int i = find(l); i <= r; i = find(i + 1))
		{
			if (i == win) continue;
			ans[i] = win;
			f[i] = i + 1;
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
    return 0;
}
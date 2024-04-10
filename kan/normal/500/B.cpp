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

const int maxn = 305;

char a[maxn][maxn];
int p[maxn], ans[maxn];
bool was[maxn];
vector<int> compa[maxn], compb[maxn];
int n;

void go(int cur, int curc)
{
	if (was[cur]) return;
	was[cur] = true;
	compa[curc].push_back(cur);
	compb[curc].push_back(p[cur]);
	for (int i = 0; i < n; i++) if (a[cur][i] == '1') go(i, curc);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &p[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) if (!was[i])
	{
		go(i, cnt++);
	}
	for (int i = 0; i < cnt; i++)
	{
		sort(compa[i].begin(), compa[i].end());
		sort(compb[i].begin(), compb[i].end());
		for (int j = 0; j < (int)compa[i].size(); j++) ans[compa[i][j]] = compb[i][j];
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
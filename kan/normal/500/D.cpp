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

const int maxn = 100005;

int w[maxn];
ll p[maxn];
vector<pair<int, int>> gr[maxn];
int n;

int go(int cur, int pr, int road)
{
	int sz = 1;
	for (auto e : gr[cur]) if (e.first != pr)
	{
		sz += go(e.first, cur, e.second);
	}
	p[road] = ((ll)sz) * (n - sz);
	return sz;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d%d", &a, &b, &w[i]);
		a--, b--;
		gr[a].push_back({b, i});
		gr[b].push_back({a, i});
	}
	go(0, -1, n);
	ll answer = 0;
	for (int i = 0; i < n - 1; i++) answer += p[i] * w[i];
	int NQ;
	scanf("%d", &NQ);
	for (int Q = 0; Q < NQ; Q++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		answer -= p[x] * w[x];
		w[x] = y;
		answer += p[x] * w[x];
		printf("%.10lf\n", (double)(((ld)(3 * answer)) / ((ll)n * (n - 1) / 2)));
	}
	return 0;
}
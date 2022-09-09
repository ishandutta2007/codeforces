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

const int maxn = 2005;

int d[maxn][maxn];
int p[maxn], s[maxn];
vector<pair<int, pair<int, int>>> all;
vector<pair<int, int>> gr[maxn];
int n;

inline int find(int a)
{
	if (p[a] == a) return a;
	return (p[a] = find(p[a]));
}

inline void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (s[a] < s[b]) swap(a, b);
	p[b] = a;
	if (s[a] == s[b]) s[a]++;
}

void go(int cur, int pr, int from, int curd)
{
	if (d[from][cur] != curd)
	{
		printf("NO\n");
		exit(0);
	}
	for (auto x : gr[cur]) if (x.first != pr) go(x.first, cur, from, curd + x.second);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &d[i][j]);
			all.push_back({d[i][j], {i, j}});
		}
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < n; i++) p[i] = i, s[i] = 0;
	for (auto e : all)
	{
		int a = e.second.first;
		int b = e.second.second;
		int dist = e.first;
		if (find(a) == find(b)) continue;
		if (dist == 0)
		{
			printf("NO\n");
			return 0;
		}
		unite(a, b);
		gr[a].push_back({b, dist});
		gr[b].push_back({a, dist});
	}
	for (int i = 0; i < n; i++) go(i, -1, i, 0);
	printf("YES\n");
	return 0;
}
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

vector<int> gr[maxn];
pair<int, int> kvs[maxn];
int a[maxn];
int p[maxn], s[maxn], sz[maxn];
int n, m;
ll answer;
bool open[maxn];

inline int find(int a)
{
	return (p[a] == a ? a : p[a] = find(p[a]));
}

inline void merge(int a, int b, int c)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	answer += (ll)c * sz[a] * sz[b];
	if (s[a] < s[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	if (s[a] == s[b]) s[a]++;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		kvs[i] = make_pair(a[i], i);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	for (int i = 0; i < n; i++) open[i] = false;
	sort(kvs, kvs + n);
	reverse(kvs, kvs + n);
	answer = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = kvs[i].second;
		open[cur] = true;
		s[cur] = 0;
		p[cur] = cur;
		sz[cur] = 1;
		for (int j = 0; j < (int)gr[cur].size(); j++) if (open[gr[cur][j]])
		{
			merge(gr[cur][j], cur, kvs[i].first);
		}
	}
	cout.precision(20);
	cout << (ld)2 * answer / n / (n - 1) << endl;
	return 0;
}
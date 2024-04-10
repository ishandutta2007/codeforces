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

int a[maxn];
pair<int, int> kvs[maxn];
vector<int> gr[maxn];
bool open[maxn];
int n, m;

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
	ll answer = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = kvs[i].second;
		for (int j = 0; j < (int)gr[cur].size(); j++) if (!open[gr[cur][j]]) answer += a[gr[cur][j]];
		open[cur] = true;
	}
	cout << answer << endl;
	return 0;
}
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
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 200005;

multiset<int> gr[maxn];
vector<int> order, odd;
int n, m;

void go(int cur)
{
// 	cout << "go " << cur << endl;
	for (auto it = gr[cur].begin(); gr[cur].size() != 0; it = gr[cur].begin())
	{
		int v = *it;
		gr[cur].erase(it);
		gr[v].erase(gr[v].find(cur));
		go(v);
	}
	order.pb(cur);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].insert(b);
		gr[b].insert(a);
	}
	for (int i = 0; i < n; i++) if (gr[i].size() % 2 != 0) odd.pb(i);
	for (int i = 0; i < (int)odd.size() / 2; i++)
	{
		gr[odd[2 * i]].insert(odd[2 * i + 1]);
		gr[odd[2 * i + 1]].insert(odd[2 * i]);
	}
	if ((odd.size() / 2 + m) % 2 == 1)
	{
		gr[0].insert(0);
		gr[0].insert(0);
	}
	go(0);
	printf("%d\n", order.size() - 1);
	for (int i = 0; i < (int)order.size() - 1; i++)
	{
		if (i % 2 == 0) printf("%d %d\n", order[i] + 1, order[i + 1] + 1);
		else printf("%d %d\n", order[i + 1] + 1, order[i] + 1);
	}
	return 0;
}
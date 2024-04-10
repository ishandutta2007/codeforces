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
int a[maxn];
int n;
vector<int> answer;

void go(int cur, int pr, int inv0, int inv1)
{
	a[cur] ^= inv0;
	if (a[cur])
	{
		answer.push_back(cur);
		inv0 ^= 1;
	}
	for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i] != pr) go(gr[cur][i], cur, inv1, inv0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		a[i] ^= t;
	}
	go(0, -1, 0, 0);
	printf("%d\n", answer.size());
	for (int i = 0; i < (int)answer.size(); i++) printf("%d\n", answer[i] + 1);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 300005;

vector<int> gr[maxn];
int c[maxn];
bool was[maxn];
int n, m;

void go(int cur, int curc)
{
    if (was[cur]) return;
    was[cur] = true;
    c[cur] = curc;
    for (int i = 0; i < (int)gr[cur].size(); i++) go(gr[cur][i], 1 - curc);
    int kv = 0;
    for (int i = 0; i < (int)gr[cur].size(); i++) kv += (c[gr[cur][i]] == c[cur]);
    if (kv > 1) c[cur] = 1 - c[cur];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b), a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    memset(was, false, sizeof(was));
    for (int i = 0; i < n; i++) go(i, 0);
    for (int i = 0; i < n; i++) printf("%d", c[i]);
	return 0;
}
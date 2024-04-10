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

const int treesize = (1 << 17);
const int maxn = 1e5 + 5;

int answer[treesize * 2], sett[treesize * 2];
int ans[maxn];
int tin[maxn], tout[maxn];
vector<int> gr[maxn], grr[maxn];
int n, m;
int timer;

inline int getans(int cur, int cl, int cr)
{
//     cout << "getans " << cur << ' ' << cl << ' ' << cr << sett[cur] << ' ' << answer[cur] << endl;
    if (sett[cur] > 0) return cr - cl + 1;
    return answer[cur];
}

void add(int cur, int cl, int cr, int l, int r, int t)
{
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r)
    {
        sett[cur] += t;
        return;
    }
    int cm = (cl + cr) / 2;
    add(cur * 2, cl, cm, l, r, t);
    add(cur * 2 + 1, cm + 1, cr, l, r, t);
    answer[cur] = getans(cur * 2, cl, cm) + getans(cur * 2 + 1, cm + 1, cr);
}

void go(int cur, int pr)
{
    tin[cur] = timer++;
//     sz[cur] = 1;
    for (int i = 0; i < gr[cur].size(); i++) if (gr[cur][i] != pr)
    {
        go(gr[cur][i], cur);
//         sz[cur] += sz[gr[cur][i]];
    }
    tout[cur] = timer - 1;
}

void go2(int cur, int pr)
{
//     cout << "go2 " << cur << ' ' << pr << ' ' << tin[cur] << ' ' << tout[cur] << endl;
    if (grr[cur].size() > 0) add(1, 0, treesize - 1, tin[cur], tout[cur], 1);
    for (int i = 0; i < grr[cur].size(); i++) add(1, 0, treesize - 1, tin[grr[cur][i]], tout[grr[cur][i]], 1);
    ans[cur] = max(1, getans(1, 0, treesize - 1));
    for (int i = 0; i < gr[cur].size(); i++) if (gr[cur][i] != pr) go2(gr[cur][i], cur);
    if (grr[cur].size() > 0) add(1, 0, treesize - 1, tin[cur], tout[cur], -1);
    for (int i = 0; i < grr[cur].size(); i++) add(1, 0, treesize - 1, tin[grr[cur][i]], tout[grr[cur][i]], -1);
}

int main()
{
    timer = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b), a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    go(0, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b), a--, b--;
        grr[a].push_back(b);
        grr[b].push_back(a);
    }
    go2(0, -1);
    for (int i = 0; i < n; i++) printf("%d ", ans[i] - 1);
	return 0;
}
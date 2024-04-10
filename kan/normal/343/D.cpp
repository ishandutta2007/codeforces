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

const int maxn = 500005;
const int treesize = 1 << 19;

int tree1[treesize * 2], tree2[treesize * 2];
vector<int> gr[maxn];
int tin[maxn], tout[maxn];
int n, q;
int timer;

void go(int cur, int pr)
{
    tin[cur] = timer++;
    for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i] != pr)
    {
        go(gr[cur][i], cur);
    }
    tout[cur] = timer - 1;
}

void push(int cur)
{
    tree1[cur * 2] = max(tree1[cur], tree1[cur * 2]);
    tree1[cur * 2 + 1] = max(tree1[cur], tree1[cur * 2 + 1]);
}

void update(int cur)
{
    tree2[cur] = max(tree2[cur], max(tree2[cur * 2], tree2[cur * 2 + 1]));
}

void set1(int cur, int cl, int cr, int l, int r, int t)
{
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r)
    {
        tree1[cur] = max(tree1[cur], t);
        return;
    }
    push(cur);
    int cm = (cl + cr) / 2;
    set1(cur * 2, cl, cm, l, r, t);
    set1(cur * 2 + 1, cm + 1, cr, l, r, t);
}

void set2(int cur, int cl, int cr, int x, int t)
{
    if (cl > x || cr < x) return;
    if (cl == cr)
    {
        tree2[cur] = max(tree2[cur], t);
        return;
    }
    int cm = (cl + cr) / 2;
    set2(cur * 2, cl, cm, x, t);
    set2(cur * 2 + 1, cm + 1, cr, x, t);
    update(cur);
}

int get1(int cur, int cl, int cr, int x)
{
    if (cl > x || cr < x) return 0;
    if (cl == cr)
    {
        return tree1[cur];
    }
    push(cur);
    int cm = (cl + cr) / 2;
    return max(get1(cur * 2, cl, cm, x),
               get1(cur * 2 + 1, cm + 1, cr, x));
}

int get2(int cur, int cl, int cr, int l, int r)
{
    if (cl > r || cr < l) return 0;
    if (cl >= l && cr <= r)
    {
        return tree2[cur];
    }
    int cm = (cl + cr) / 2;
    return max(get2(cur * 2, cl, cm, l, r),
               get2(cur * 2 + 1, cm + 1, cr, l, r));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    timer = 0;
    go(0, -1);
//     for (int i = 0; i < n; i++)
//     {
//         cout << tin[i] << ' ' << tout[i] << endl;        
//     }
    scanf("%d", &q);
    for (int T = 0; T < q; T++)
    {
        int t, v;
        scanf("%d%d", &t, &v);
        v--;
        if (t == 1) set1(1, 0, treesize - 1, tin[v], tout[v], T + 1);
        if (t == 2) set2(1, 0, treesize - 1, tin[v], T + 1);
        if (t == 3)
        {
            int last1 = get1(1, 0, treesize - 1, tin[v]);
            int last0 = get2(1, 0, treesize - 1, tin[v], tout[v]);
//             cout << last1 << ' ' << last0 << endl;
            printf("%d\n", (last1 > last0 ? 1 : 0));
        }
    }
	return 0;
}
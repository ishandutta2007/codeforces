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

const int treesize = 1 << 30;

struct tnode
{
    tnode *l, *r;
    int max;

    tnode()
    {
        l = NULL;
        r = NULL;
        max = 0;
    }
};

typedef tnode* pnode;

pnode sett(pnode cur, int cl, int cr, int l, int r, int t)
{
    if (cl > r || cr < l) return cur;
    if (cur == NULL) cur = new tnode;
    if (cl >= l && cr <= r)
    {
//         cout << "in " << cl << ' ' << cr << endl;
        cur->max = max(cur->max, t);
        return cur;
    }
    int cm = (cl + cr) / 2;
    cur->l = sett(cur->l, cl, cm, l, r, t);
    cur->r = sett(cur->r, cm + 1, cr, l, r, t);
    return cur;
}

int get(pnode cur, int cl, int cr, int x)
{
    if (cur == NULL) return 0;
    int cm = (cl + cr) / 2;
    if (x <= cm) return max(cur->max, get(cur->l, cl, cm, x));
    else return max(cur->max, get(cur->r, cm + 1, cr, x));
}

pnode root[2];
set<int> was[2];
int n, m;
char t[5];

void doall(int t0, int t1, int wh)
{
    if (was[t0].count(wh))
    {
        printf("%d\n", 0);
        return;
    }
    was[t0].insert(wh);
    int deep = get(root[t0], 0, treesize - 1, wh);
//     cout << "deep = " << deep << endl;
    int ans = n + 1 - wh - deep;
    printf("%d\n", ans);
//     cout << "set " << n + 1 - wh - ans + 1 << ' ' <<  n + 1 - wh << ' ' <<  wh << endl;
    root[t1] = sett(root[t1], 0, treesize - 1, n + 1 - wh - ans + 1, n + 1 - wh, wh);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d%s", &y, &x, t);
        if (t[0] == 'U')
        {
            doall(0, 1, y);
        } else
        {
            doall(1, 0, x);
        }
    }
	return 0;
}
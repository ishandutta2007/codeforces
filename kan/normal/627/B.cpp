#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int treesize = 1 << 18;

int treea[2 * treesize], treeb[2 * treesize];
int n, k, a, b, q;

inline void upd(int *tree, int x)
{
    x /= 2;
    while (x > 0)
    {
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
        x /= 2;
    }
}

inline int get(int *tree, int cur, int cl, int cr, int l, int r)
{
    if (cl > r || cr < l) return 0;
    if (cl >= l && cr <= r) 
    {
//         cout << cl << ' ' << cr << ' ' << tree[cur] << endl;
        return tree[cur];
    }
    int cm = (cl + cr) / 2;
    return get(tree, cur * 2, cl, cm, l, r) + get(tree, cur * 2 + 1, cm + 1, cr, l, r);
}

int main()
{
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x--;
            treeb[treesize + x] = min(b, treeb[treesize + x] + y);
            upd(treeb, treesize + x);
            treea[treesize + x] = min(a, treea[treesize + x] + y);
            upd(treea, treesize + x);
        } else
        {
            int p;
            scanf("%d", &p);
            p--;
            printf("%d\n", get(treeb, 1, 0, treesize - 1, 0, p - 1) + get(treea, 1, 0, treesize - 1, p + k, n - 1));
        }
    }
    return 0;
}
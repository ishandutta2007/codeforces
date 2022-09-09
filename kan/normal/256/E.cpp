#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int MOD = 777777777;

struct tnode
{
    int x, y;
    tnode *l, *r;
    int ans;
    
    tnode(){}
    tnode(int x): x(x)
    {
        y = rand();
        l = NULL;
        r = NULL;
        ans = x;
    }
};

typedef tnode* pnode;

inline int getans(pnode cur)
{
    if (cur == NULL) return 1;
    return cur->ans;
}

inline void update(pnode cur)
{
    if (cur ==  NULL) return;
    cur->ans = ((((ll)cur->x * getans(cur->l)) % MOD) * getans(cur->r)) % MOD;
}

pnode merge(pnode l, pnode r)
{
    if (l == NULL) return r;
    if (r == NULL) return l;
    if (l->y < r->y)
    {
        r->l = merge(l, r->l);
        update(r);
        return r;
    } else
    {
        l->r = merge(l->r, r);
        update(l);
        return l;
    }
}

void split(pnode cur, int x, pnode &l, pnode &r)
{
    if (cur == NULL)
    {
        l = NULL;
        r = NULL;
        return;
    }
    if (cur->x < x)
    {
        l = cur;
        split(cur->r, x, cur->r, r);
        update(l);
    } else
    {
        r = cur;
        split(cur->l, x, l, cur->l);
        update(r);
    }
}

pnode root = NULL;
int n, m;
int a[100005];
int ans[100005][4][4];
int can[4][4];
ll answer;
set<int> was;

void adds(int x)
{
    pnode l, r;
    split(root, x + 1, l, r);
    root = merge(l, merge(new tnode(x), r));
}

void rems(int x)
{
    pnode l, r, m;
    split(root, x + 1, l, r);
    split(l, x, l, m);
    pnode t = m;
    m = merge(m->l, m->r);
    root = merge(l, merge(m, r));
}

inline int getansr(int b, int f, int len)
{
    int answer = 0;
    if (f == 0)
    {
        for (int i = 1; i <= 3; i++) answer = (answer + ans[len][b][i]) % MOD;
    } else answer = ans[len][b][f];
    return answer;
}

int getans(int b, int f, int len)
{
    int answer = 0;
    if (b == 0)
    {
        for (int i = 1; i <= 3; i++) answer = (answer + getansr(i, f, len)) % MOD;
    } else answer = getansr(b, f, len);
    return answer;
}

void rem(int l, int r)
{
    if (l == -1)
    {
        if (r == n)
        {
            rems(getans(0, 0, n));
        } else
        {
            rems(getans(0, a[r], r + 1));
        }
    } else
    {
        if (r == n)
        {
            rems(getans(a[l], 0, n - l));
        } else
        {
            rems(getans(a[l], a[r], r - l + 1));
        }
    }
}

void add(int l, int r)
{
    if (l == -1)
    {
        if (r == n)
        {
            adds(getans(0, 0, n));
        } else
        {
            adds(getans(0, a[r], r + 1));
        }
    } else
    {
        if (r == n)
        {
            adds(getans(a[l], 0, n - l));
        } else
        {
            adds(getans(a[l], a[r], r - l + 1));
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++) scanf("%d", &can[i][j]);
    }
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= 3; i++) ans[1][i][i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int b = 1; b <= 3; b++)
        {
            for (int f = 1; f <= 3; f++)
            {
                for (int j = 1; j <= 3; j++) if (can[f][j] == 1)
                {
                    ans[i + 1][b][j] = (ans[i + 1][b][j] + ans[i][b][f]) % MOD;
                }
            }
        }
    }
    answer = getans(0, 0, n);
    adds(answer);
    was.clear();
    was.insert(-1);
    was.insert(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y), x--;
        if (a[x] == y)
        {
            printf("%d\n", getans(root));
            continue;
        }
        set<int>::iterator wh = was.lower_bound(x);
        if (*wh == x)
        {
            set<int>::iterator prev = wh;
            prev--;
            set<int>::iterator next = wh;
            next++;
            rem(*prev, *wh);
            rem(*wh, *next);
            if (y == 0)
            {
                a[x] = 0;
                add(*prev, *next);
                was.erase(*wh);
            } else
            {
                a[x] = y;
                add(*prev, *wh);
                add(*wh, *next);
            }
        } else
        {
            set<int>::iterator prev = wh;
            prev--;
            rem(*prev, *wh);
            a[x] = y;
            add(*prev, x);
            add(x, *wh);
            was.insert(x);
        }
        printf("%d\n", getans(root));
    }
	return 0;
}
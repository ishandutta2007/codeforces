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
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

struct tnode
{
    tnode *l, *r;
    int x, y;
    int size;
    
//     tnode(){}
    tnode(int x): x(x)
    {
        l = NULL;
        r = NULL;
        size = 1;
        y = (rand() << 15) ^ rand();
    }
};

typedef tnode* pnode;

inline int getsize(pnode cur)
{
    return (cur == NULL ? 0 : cur->size);
}

inline void update(pnode cur)
{
    cur->size = 1 + getsize(cur->l) + getsize(cur->r);
}

pnode merge(pnode l, pnode r)
{
    if (l == NULL) return r;
    if (r == NULL) return l;
    if (l->y > r->y)
    {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else
    {
        r->l= merge(l, r->l);
        update(r);
        return r;
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
    if (cur->x >= x)
    {
        split(cur->l, x, l, cur->l);
        r = cur;
        update(r);
    } else
    {
        split(cur->r, x, cur->r, r);
        l = cur;
        update(l);
    }
}

void splitone(pnode cur, pnode &l, pnode &r)
{
    assert(cur != NULL);
    if (cur->l == 0)
    {
        l = cur;
        r = cur->r;
        cur->r = NULL;
        update(cur);
    } else
    {
        splitone(cur->l, l, cur->l);
        r = cur;
        update(cur);
    }
}

inline void erase(pnode &cur, int x)
{
    pnode l, m, r;
    split(cur, x, l, r);
    splitone(r, m, r);
    cur = merge(l, r);
}

inline void insert(pnode &cur, int x)
{
    pnode l, r;
    split(cur, x, l, r);
    cur = merge(l, merge(new tnode(x), r));
}

int count(pnode cur, int k)
{
    if (cur == NULL) return 0;
    if (cur->x >= k) return getsize(cur->r) + 1 + count(cur->l, k);
    else return count(cur->r, k);
}

typedef map<int, int>::iterator miter;

struct tans
{
    pnode sorted;
    map<int, int> *kv;
};

typedef tans* pans;

inline pans mergeans(pans a, pans b)
{
    if (a == NULL) return b;
    if (a->kv->size() < b->kv->size()) swap(a, b);
    for (miter it = b->kv->begin(); it != b->kv->end(); it++)
    {
        int &wh = (*a->kv)[it->first];
        if (wh != 0) erase(a->sorted, wh);
        wh += it->second;
        insert(a->sorted, wh);
    }
    return a;
}

inline pans mergeans(pans a, int b)
{
//     cout << "merge1 " << a << ' ' << b << endl;
    if (a == NULL)
    {
        a = new tans;
        a->sorted = NULL;
        a->kv = new map<int, int>;
    }
//     cout << (void*)((a->kv)) << endl;
    int &wh = (*(a->kv))[b];
//     cout << "was " << wh << endl;
    if (wh != 0) erase(a->sorted, wh);
    wh += 1;
    insert(a->sorted, wh);
    return a;
}

const int maxn = 100005;

vector<int> gr[maxn];
vector<pair<int, int> > q[maxn];
int ans[maxn];
int c[maxn];
int n, m;

pans go(int cur, int pr)
{
//     cout << "go " << cur << endl;
    pans curans = NULL;
    for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i] != pr)
    {
        curans = mergeans(curans, go(gr[cur][i], cur));
    }
    curans = mergeans(curans, c[cur]);
//     cout << "all ok, size = " << curans->kv->size() << endl;
    for (int i = 0; i < (int)q[cur].size(); i++)
    {
        int k = q[cur][i].first;
        ans[q[cur][i].second] = count(curans->sorted, k);
    }
    return curans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int v, k;
        scanf("%d%d", &v, &k);
        v--;
        q[v].push_back(make_pair(k, i));
    }
    go(0, -1);
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}
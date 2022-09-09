/**
 * This is solution for problem two-color-metro
 * This is nk_ok.cpp
 * 
 * @author: Nikolay Kalinin
 * @date: Fri, 23 Nov 2018 17:57:48 +0300
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

mt19937 mt;

int cnt = 0;

struct tnode
{
    tnode *l, *r;
    int x;
    int size;
    
    tnode() {}
    tnode(const tnode &other): l(other.l), r(other.r), x(other.x), size(other.size)
    {
        cnt++;
    }
    tnode(int x): x(x)
    {
        l = NULL;
        r = NULL;
        size = 1;
    }
};

typedef tnode* pnode;

tnode mem[(int)1e7];
int curmem;

inline pnode newnode(tnode &other)
{
    mem[curmem] = tnode(other);
    pnode ret = mem + curmem;
    curmem++;
    return ret;
}

inline pnode newnode(int x)
{
    mem[curmem] = tnode(x);
    pnode ret = mem + curmem;
    curmem++;
    return ret;
}

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
    if (l == NULL) return (r == NULL ? NULL : newnode(*r));
    if (r == NULL) return newnode(*l);
    if (mt() % (l->size + r->size) < l->size)
    {
        l = newnode(*l);
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else
    {
        r = newnode(*r);
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

int depth;

void split(pnode cur, int x, pnode &l, pnode &r)
{
    if (cur == NULL)
    {
        l = NULL;
        r = NULL;
        return;
    }
    cur = newnode(*cur);
    int szl = getsize(cur->l);
//     cout << "in split " << szl << endl;
//     depth++;
    if (szl >= x)
    {
        split(cur->l, x, l, cur->l);
        r = cur;
        update(r);
    } else
    {
        split(cur->r, x - szl - 1, cur->r, r);
        l = cur;
        update(l);
    }
}

inline pnode getseg(pnode cur, int lpos, int rpos)
{
//     cout << "getseg " << getsize(cur) << ' ' << lpos << ' ' << rpos << endl;
    pnode l, m, r;
    if (rpos < getsize(cur)) split(cur, rpos, l, r);
    else l = cur;
    if (lpos == 0) return l;
    depth = 0;
    split(l, lpos, l, m);
//     cerr << depth << endl;
//     cout << "returns " << getsize(l) << ' ' << getsize(m) << ' ' << getsize(r) << endl;
//     cout << getsize(cur) << endl;
    return m;
}

vector<int> go;
vector<int> was;

pnode build(int l, int r)
{
    if (l > r) return NULL;
    int m = (l + r) / 2;
    pnode cur = newnode(go[m]);
    cur->l = build(l, m - 1);
    cur->r = build(m + 1, r);
    update(cur);
    return cur;
}

void toarray(pnode cur)
{
    if (cur == NULL) return;
    toarray(cur->l);
    go.pb(cur->x);
    toarray(cur->r);
}

int main()
{
    curmem = 0;
//     cerr << sizeof(tnode) << endl;
    int n, m, start;
    ll T;
    cin >> n >> m;
    cin >> start >> T;
    start--;
    go.resize(n);
    iota(all(go), 0);
    pnode root = build(0, n - 1);
    for (int step = 1; step <= n; step++)
    {
        pnode l;
        if (m + step <= n)
        {
            l = getseg(root, step, m + step);
        } else
        {
            pnode ll = getseg(root, step, n);
            pnode lr = getseg(root, 0, (m + step) % n);
            l = merge(ll, lr);
        }
        pnode r;
        if (m - step >= 0)
        {
            r = getseg(root, m - step, n - step);
        } else
        {
            pnode rl = getseg(root, m - step + n, n);
            pnode rr = getseg(root, 0, n - step);
            r = merge(rl, rr);
        }
//         cerr << step << ' ' << getsize(l) << ' ' << getsize(r) << endl;
        root = merge(l, r);
        if (step % 500 == 0)
        {
            go.clear();
            toarray(root);
            curmem = 0;
            root = build(0, n - 1);
        }
//         go.clear();
//         toarray(root);
//         for (auto t : go) cout << t << ' ';
//         cout << endl;
    }
    go.clear();
    toarray(root);
    cerr << clock() << ' ' << cnt << endl;
//     for (auto t : go) cout << t << ' ';
//     cout << endl;
    while (T % n != 0)
    {
        if (start < m) start = (start + T) % n;
        else start = ((start - T) % n + n) % n;
        T--;
    }
    T /= n;
    was.resize(n, -1);
    int cur = start;
    int it = 0;
    while (was[cur] == -1)
    {
        was[cur] = it;
        cur = go[cur];
        it++;
    }
    int cycle = (it - was[cur]);
    int precycle = was[cur];
    if (T > precycle)
    {
        T -= (ll)((T - precycle) / cycle) * cycle;
    }
    while (T > 0)
    {
        start = go[start];
        T--;
    }
    cout << start + 1 << endl;
    return 0;
}
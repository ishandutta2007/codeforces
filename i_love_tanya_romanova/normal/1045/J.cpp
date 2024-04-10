#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 1e5 + 100;
vector <pair <int, char>> g[N];

const int LOG = 18;
int p[N][LOG], h[N], pc[N];

void dfs(int v, int par, int ch, char cch = '-')
{
//    eprintf("%d -> %d\n", par, v);
    pc[v] = cch;
    h[v] = ch;
    p[v][0] = par;
    for (int i = 1; i < LOG; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];

    for (auto toc : g[v])
    {
        int to = toc.first;
        if (to == par) continue;
        dfs(to, v, ch + 1, toc.second);
    }
}


int goUp(int v, int d)
{
    for (int i = 0; i < LOG; i++)
        if (d & (1 << i))
            v = p[v][i];
    return v;
}

int lca(int a, int b)
{
    if (h[a] < h[b]) swap(a, b);
    a = goUp(a, h[a] - h[b]);
//    eprintf("a = %d, b = %d\n", a, b);
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (p[a][i] != p[b][i])
        {
            a = p[a][i];
            b = p[b][i];
        }
    return p[a][0];
}

int ans[N];
char str[2 * N];
int z[2 * N];

void calcZ(int n)
{
    int wl = 0, wr = 1;
    for (int i = 1; i < n; i++)
    {
        if (i < wr)
            z[i] = min(wr - i, z[i - wl]);
        else 
            z[i] = 0;
        while (i + z[i] < n && str[i + z[i]] == str[z[i]])
            z[i]++;
        if (i + z[i] > wr)
        {
            wl = i;
            wr = i + z[i];
        }
    }
}


struct Qu
{
    int id;
    string s;
    int k;
    Qu() : id(), s(), k() {}
    Qu(int _id, string _s, int _k) : id(_id), s(_s), k(_k) {}
};

vector <Qu> qs[N];
const int MAX_LEN = 104;

void addQ(int id, string s, int v, int k)
{
    qs[v].emplace_back(id, s, k);
}
const int SM = 30;
const int SZ = N * MAX_LEN;
const int MSZ = SZ / SM;
int cnt[SZ];
int trieSz = 1;
const int LET = 31;
const int LETX = 5;

int st[SZ];
int go[SZ];
int gonx[SZ];
int goSz = 1;
map <int, int> ms[MSZ];
int mCnt = 1;


int getGo(int v, int c)
{
    v = st[v];
    while (v > 0)
    {
        if ((go[v] & LET) == c)
            return go[v] >> LETX;
        v = gonx[v];
    }
    if (v != 0)
    {
        v = -v;
        if (ms[v].count(c)) return ms[v][c];
    }
    return -1;
}

void setGo(int v, int c, int to)
{
 //   eprintf("setGo %d %d : %d\n", v, c, to);
    if (st[v] == -1)
    {
        go[goSz] = ((to << LETX) | c);
        st[v] = goSz++;
        return;
    }
    int ccnt = 0;
    v = st[v];
    int pv = v;
    while (v > 0)
    {
        ccnt++;
        pv = v;
        v = gonx[v];
    }
    if (ccnt < SM)
    {
//      eprintf("go at %d -> %d\n", v, goSz);
        gonx[goSz] = -1;
        go[goSz] = ((to << LETX) | c);
        gonx[pv] = goSz++;
        return;
    }

    if (v == 0)
        v = gonx[pv] = -(mCnt++);

    v = -v;
    ms[v][c] = to;
}

int addWord(string &s, int k)
{
    int v = 0;
    for (char c : s)
    {
        c -= 'a';
//        int cx = (((c - 'a') << HACK_LOG) | (v & ((1 << HACK_LOG) - 1)));
//        int vx = (v >> HACK_LOG);
        if (getGo(v, c) == -1)
        {
            if (k == 0)
                return 0;
            setGo(v, c, trieSz++);
        }
#ifdef LOCAL
  //      eprintf("go %d %d == %d\n", v, c, getGo(v, c));
#endif
        v = getGo(v, c);
        cnt[v] += k;
    }
    return v;
}

void dfsSolve(int v, int par)
{
    string s = "";
    int x = v;
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (x == 0) break;
        s.push_back(pc[x]);
        x = p[x][0];
    }
    addWord(s, 1);

    for (auto q : qs[v])
    {
        int pos = addWord(q.s, 0);
        ans[q.id] += cnt[pos] * q.k;
    }

    for (auto toc : g[v])
    {
        int to = toc.first;
        if (to == par) continue;
        dfsSolve(to, v);
    }
    addWord(s, -1);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    memset(st, -1, sizeof st);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        char ch[2];
        scanf("%d%d%s", &a, &b, ch);
        a--;
        b--;
        g[a].emplace_back(b, ch[0]);
        g[b].emplace_back(a, ch[0]);
    }
    dfs(0, 0, 0);
    int q;
    scanf("%d", &q);
    for (int it = 0; it < q; it++)
    {
        int a, b;
        char ch[105];
        scanf("%d%d%s", &a, &b, ch);
        a--;
        b--;
        string s = string(ch);
        int l = lca(a, b);
        vector <int> v = {a, b};
//        eprintf("it = %d\n", it);
        for (int &x : v)
        {
            if (h[x] - h[l] >= (int) s.size())
            {
                addQ(it, s, x, 1);
                x = goUp(x, h[x] - h[l] - (int) s.size() + 1);
                addQ(it, s, x, -1);
            }
            reverse(s.begin(), s.end());
        }
        a = v[0];
        b = v[1];
        string t;
        while (a != l)
        {
            t.push_back(pc[a]);
            a = p[a][0];
        }
        int k = (int) t.length();
//        eprintf("it = %d\n", it);
//        eprintf("a = %d, b = %d, l = %d\n", a, b, l);
        while (b != l)
        {
            t.push_back(pc[b]);
            b = p[b][0];
        }
//        eprintf("it = %d\n", it);
        reverse(t.begin() + k, t.end());
        for (int i = 0; i < (int) s.size(); i++)
            str[i] = s[i];
        for (int i = 0; i < (int) t.size(); i++)
            str[(int) s.size() + i] = t[i];
        calcZ((int) s.size() + (int) t.size());
        for (int i = 0; i < k; i++)
            if (z[(int) s.size() + i] >= (int) s.size())
                ans[it]++;
    }

    dfsSolve(0, 0);

    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i]);

	return 0;
}
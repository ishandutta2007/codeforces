#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 100000;

vector<ii> g[maxn];
int col[maxn];

vi cycle;
vi ed;
set<int> ce;
map<ii, int> M;
map<int, int> wh;

vi st;

void dfs(int x, int c = 1)
{
    if (sz(cycle)) return;
    col[x] = c;
    st.pb(x);
    for (int i = 0; i < sz(g[x]); i++)
    {
        if (sz(cycle)) return;
        if (col[g[x][i].first] != 0)
        {
            if (col[g[x][i].first] == c)
            {
                cycle.pb(M[ii(g[x][i].first, x)]);
                ed.pb(g[x][i].first);
                while (st[sz(st) - 1] != g[x][i].first)
                {
                    int ind = sz(st) - 2;
                    cycle.pb(M[ii(st[sz(st) - 1], st[ind])]);
                    ed.pb(st[sz(st) - 1]);
                    st.pop_back();
                }
                return;
            }
        }
        else
            dfs(g[x][i].first, c == 1 ? 2 : 1);
    }
    if (sz(st))
        st.pop_back();
}

vector<ii> v;

void save()
{
    printf("0\n");
    exit(0);
}

int start;

int Dec(int x)
{
    x--;
    if (x < 0) x = sz(cycle) - 1;
    return x;
}

int Len(int x, int y)
{
    if (y > x)
        return y - x;
    return sz(cycle) - y + x;
}

void Add(int x, int y, int c)
{
    if (x == y) return;
    int what = (Len(x, y) % 2 == 0) ^ (c == 1);
    if (what)
        v.pb(ii(x, y));
    else
        v.pb(ii(y, x));
}

bool inside(int l, int r, int x)
{
    if (r >= l)
        return x >= l && x < r;
    else
        return x < r || x >= l;
}

void go(int x, int c = 1)
{
    col[x] = c;
    if (start != -1 && wh.count(x))
    {
        Add(start, wh[x], c);
    }
    for (int i = 0; i < sz(g[x]); i++)
    {
        if (ce.count(g[x][i].second)) continue;
        if (col[g[x][i].first] != 0)
        {
            if (col[g[x][i].first] == c)
                save();
        }
        else
            go(g[x][i].first, c == 1 ? 2 : 1);
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if (x == y) save();
        g[x].pb(ii(y, i));
        g[y].pb(ii(x, i));
        M[ii(x, y)] = i;
        M[ii(y, x)] = i;
    }
    memset(col, 0, sizeof(col));
    for (int i = 0; i < n; i++)
    {
        if (col[i]) continue;
        cycle.clear();
        dfs(i);
        if (sz(cycle) == 0) continue;
        break;
    }
    if (!sz(cycle))
    {
        printf("%d\n", m);
        for (int i = 0; i < m; i++)
            printf("%d ", i + 1);
        printf("\n");
        exit(0);
    }
    ce = set<int>(all(cycle));
    for (int i = 0; i < sz(ed); i++)
    {
        wh[ed[i]] = i;
    }
    memset(col, 0, sizeof(col));
    for (int i = 0; i < n; i++)
    {
        if (col[i]) continue;
        start = wh.count(i) ? wh[i] : -1;
        if (start == -1) continue;
        go(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (col[i]) continue;
        start = wh.count(i) ? wh[i] : -1;
        go(i);
    }
    int cnt = 0;
    vector<ii> ev;
    for (int i = 0; i < sz(v); i++)
    {
        ev.pb(ii(v[i].first, 1));
        ev.pb(ii(v[i].second, -1));
        if (inside(v[i].first, v[i].second, 0))
            cnt++;
    }
    sort(all(ev));
    int ind = 0;
    while (ind < sz(ev) && ev[ind].first == 0) ind++;
    vi vr;
    for (int i = 0; i < sz(cycle); i++)
    {
        if (cnt == sz(v)) vr.pb(cycle[i]);
        while (ind < sz(ev) && ev[ind].first == i + 1)
        {
            cnt += ev[ind].second;
            ind++;
        }
    }
    sort(all(vr));
    cout << sz(vr) << "\n";
    for (int i = 0; i < sz(vr); i++)
        printf("%d ", vr[i] + 1);
    printf("\n");
    return 0;
}
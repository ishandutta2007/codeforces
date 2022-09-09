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

struct tp
{
    int h, l, r;
    tp(){}
    tp(int h, int l, int r): h(h), l(l), r(r) {}
};

inline bool operator <(const tp &a, const tp &b)
{
    return a.h > b.h;
}

const int OPEN = 0;
const int CLOSE = 1;

struct tsob
{
    int x, id, t;
    tsob(){}
    tsob(int x, int id, int t): x(x), id(id), t(t) {}
};

inline bool operator <(const tsob &a, const tsob &b)
{
    return (a.x < b.x) || (a.x == b.x && a.t == CLOSE && b.t == OPEN);
}

const int maxn = 100005;
const int inf = 1e9;

tp p[maxn];

class cmph
{
public:
    inline bool operator ()(const int &a, const int &b)
    {
        return p[a].h < p[b].h;
    }
};

typedef set<int, cmph> set_int;
typedef set_int::iterator sint_iter;
typedef set<pair<int, int> > set_pii;
typedef set_pii::iterator spii_iter;

vector<tsob> sob;
set_int curp;
set_pii edges;
vector<int> gr[maxn];
int ans[maxn];
int n, height;

int main()
{
    scanf("%d%d", &n, &height);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &p[i].h, &p[i].l, &p[i].r);
    }
    p[n] = tp(height, -inf, inf);
    n++;
    p[n] = tp(0, -inf, inf);
    n++;
    sort(p, p + n);
//     cerr << "p sorted " << endl;
    for (int i = 1; i < n - 1; i++)
    {
        sob.push_back(tsob(p[i].l, i, OPEN));
        sob.push_back(tsob(p[i].r, i, CLOSE));
    }
//     cerr << "sob created " << sob.size() << endl;
    sort(sob.begin(), sob.end());
//     cerr << "sob sorted " << endl;
    curp.insert(0);
    curp.insert(n - 1);
    for (int i = 0; i < (int)sob.size(); i++)
    {
//         cerr << "sob " << i << endl;
        if (sob[i].t == OPEN)
        {
            sint_iter wh = curp.lower_bound(sob[i].id);
            sint_iter prev = wh;
            prev--;
            edges.erase(make_pair(*prev, *wh));
            edges.insert(make_pair(*prev, sob[i].id));
            edges.insert(make_pair(sob[i].id, *wh));
            curp.insert(sob[i].id);
        } else curp.erase(sob[i].id);
    }
//     cerr << "edges done" << endl;
    for (spii_iter it = edges.begin(); it != edges.end(); it++) gr[it->first].push_back(it->second);
    ans[0] = 2 * inf;
    for (int i = 1; i < n; i++)
    {
        ans[i] = 0;
        for (int j = 0; j < (int)gr[i].size(); j++)
        {
            int next = gr[i][j];
            ans[i] = max(ans[i], min(ans[next], min(p[next].r, p[i].r) - max(p[next].l, p[i].l)));
        }
    }
    cout << ans[n - 1] << endl;
	return 0;
}
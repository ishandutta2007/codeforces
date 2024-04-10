#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxv = 1005;
const int maxn = 405;
const int inf = 1e9;

struct tedge
{
    int v;
    int f, maxf;
    double c;
    int o;
    tedge(){}
    tedge(int v, int f, int maxf, double c, int o): v(v), f(f), maxf(maxf), c(c), o(o) {}
};

namespace std
{
    ostream& operator << (ostream &out, tedge a)
    {
        out << "(to: " << a.v << " flow: " << a.f << " maxf: " << a.maxf << " c: " << a.c << " o: " << a.o << ")";
        return out;
    }
}

vector<tedge> gr[maxv];
double d[maxv];
int maxf[maxv], from[maxv];
bool inq[maxv];
queue<int> q;
int x[maxn], y[maxn];
int n;

inline void push(int x)
{
    inq[x] = true;
    q.push(x);
}

inline int pop()
{
    int x = q.front();
    q.pop();
    inq[x] = false;
    return x;
}

inline double getdist(int a, int b)
{
    int dx = x[b] - x[a];
    int dy = y[b] - y[a];
    return sqrt((double)(dx * dx + dy * dy));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    int all = 1 + 2 * n + 1;
    for (int i = 0; i < n; i++)
    {
        gr[0].push_back(tedge(i + 1, 0, 2, 0, gr[i + 1].size()));
        gr[i + 1].push_back(tedge(0, 0, 0, 0, gr[0].size() - 1));
    }
    for (int i = 0; i < n; i++)
    {
        gr[all - 1].push_back(tedge(n + 1 + i, 0, 0, 0, gr[n + 1 + i].size()));
        gr[n + 1 + i].push_back(tedge(all - 1, 0, 1, 0, gr[all - 1].size() - 1));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) if (y[i] > y[j])
        {
            int wh2 = n + 1 + j;
            gr[i + 1].push_back(tedge(wh2, 0, 1, getdist(i, j), gr[wh2].size()));
            gr[wh2].push_back(tedge(i + 1, 0, 0, -getdist(i, j), gr[i + 1].size() - 1));
        }
    }
    double answer = 0;
    int flow = 0;
    for (int IT = 0; IT < n; IT++)
    {
        //         cout << "new iteration " << IT << endl;
        for (int i = 0; i < all; i++) inq[i] = false, d[i] = inf, from[i] = -1, maxf[i] = 0;
        d[0] = 0;
        maxf[0] = inf;
        push(0);
        while (!q.empty())
        {
            int cur = pop();
//             cout << "now " << cur << ' ' << d[cur] << endl;
            for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i].f < gr[cur][i].maxf && d[gr[cur][i].v] > d[cur] + gr[cur][i].c)
            {
                d[gr[cur][i].v] = d[cur] + gr[cur][i].c;
                maxf[gr[cur][i].v] = min(maxf[cur], gr[cur][i].maxf - gr[cur][i].f);
                from[gr[cur][i].v] = gr[cur][i].o;
                if (!inq[gr[cur][i].v]) push(gr[cur][i].v);
            }
        }
        if (maxf[all - 1] == 0) break;
        answer += d[all - 1] * maxf[all - 1];
        flow += maxf[all - 1];
        int cur = all - 1;
        while (from[cur] != -1)
        {
            gr[cur][from[cur]].f -= maxf[all - 1];
            gr[gr[cur][from[cur]].v][gr[cur][from[cur]].o].f += maxf[all - 1];
            cur = gr[cur][from[cur]].v;
        }
    }
    if (flow != n - 1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout.precision(20);
    cout << answer << endl;
    return 0;
}
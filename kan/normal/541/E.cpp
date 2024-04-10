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

#define next next_Asdgcv

const int inf = 1e5 + 5;

const int maxn = 1005;
const int maxE = 200005;

int next[maxE], edge[maxE];
int first[maxn];
bool was[maxn];
int c[maxn];
vector<int> comp[maxn];
int answer[maxn];
int o[maxn];
int d[maxn];
int n, m;
int ke;

inline void add(int a, int b)
{
    next[ke] = first[a];
    edge[ke] = b;
    first[a] = ke;
    ke++;
}

void go(int cur, int curc, int curcomp)
{
//     cout << "go " << cur << ' ' << curc << ' ' << curcomp << endl;
    if (was[cur])
    {
        if (c[cur] != curc)
        {
            printf("-1\n");
            exit(0);
        }
        return;
    }
    was[cur] = true;
    c[cur] = curc;
    for (int e = first[cur]; e != -1; e = next[e])
    {
//         cout << "from " << cur << " to " << edge[e] << endl;
        go(edge[e], 1 - curc, curcomp);
    }
    comp[curcomp].push_back(cur);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) first[i] = -1;
    ke = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        add(a, b);
        add(b, a);
    }
    int kc = 0;
    for (int i = 0; i < n; i++) if (!was[i])
    {
        go(i, 0, kc++);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) d[j] = inf;
        d[i] = 0;
        int bo = 0;
        int eo = 1;
        o[0] = i;
        while (eo > bo)
        {
            int cur = o[bo++];
            answer[i] = d[cur];
            for (int e = first[cur]; e != -1; e = next[e])
            {
                if (d[edge[e]] > d[cur] + 1)
                {
                    d[edge[e]] = d[cur] + 1;
                    o[eo++] = edge[e];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < kc; i++)
    {
        int curmax = 0;
        for (auto v : comp[i]) curmax = max(curmax, answer[v]);
        ans += curmax;
    }
    cout << ans << endl;
	return 0;
}
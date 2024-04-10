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

const int maxn = 405;

vector<int> gr[maxn], grr[maxn], gr2[maxn], grr2[maxn];
bool vis[maxn];
int c[maxn];
bool was[maxn][2];
char s[maxn], answer[maxn];
vector<int> order;

char types[maxn], type1[10], type2[10];
int t[maxn];
int L, n, m;

void toorder(int cur)
{
    if (vis[cur]) return;
    vis[cur] = true;
    for (auto x : gr[cur]) toorder(x);
    for (auto x : gr2[cur]) toorder(x);
    order.pb(cur);
}

void mark(int cur, int curc)
{
    if (vis[cur]) return;
    vis[cur] = true;
    c[cur] = curc;
    for (auto x : grr[cur]) mark(x, curc);
    for (auto x : grr2[cur]) mark(x, curc);
}

bool poss()
{
//     cout << "poss " << endl;
//     for (int i = 0; i < 2 * n; i++)
//     {
//         cout << i << ": ";
//         for (auto x : gr[i]) cout << x << ' ';
//         cout << " and ";
//         for (auto x : gr2[i]) cout << x << ' ';
//         cout << endl;
//     }
    order.resize(0);
    for (int i = 0; i < 2 * n; i++) vis[i] = false;
    for (int i = 0; i < 2 * n; i++) if (!vis[i]) toorder(i);
    for (int i = 0; i < 2 * n; i++) vis[i] = false;
    int kcomp = 0;
    for (int i = (int)order.size() - 1; i >= 0; i--) if (!vis[order[i]])
    {
        mark(order[i], kcomp++);
    }
    for (int i = 0; i < n; i++) if (c[i] == c[i + n]) return false;
    return true;
}

void go(int cur, bool follow)
{
//     cout << "go " << cur << ' ' << follow << endl;
    if (!poss()) return;
    if (cur == n)
    {
        answer[n] = '\0';
        printf("%s\n", answer);
        exit(0);
    }
    gr2[cur].clear();
    gr2[cur + n].clear();
    int start = 0;
    if (follow)
    {
        int curt = t[s[cur] - 'a'];
        gr2[cur + (1 - curt) * n].pb(cur + curt * n);
        grr2[cur + curt * n].pb(cur + (1 - curt) * n);
        answer[cur] = s[cur];
        go(cur + 1, true);
        gr2[cur + (1 - curt) * n].clear();
        grr2[cur + curt * n].clear();
        start = s[cur] - 'a' + 1;
    }
    was[cur][0] = false;
    was[cur][1] = false;
    for (int i = start; i < L; i++) if (!was[cur][t[i]])
    {
//         cout << cur << " choose " << i << endl;
        answer[cur] = 'a' + i;
        int curt = t[i];
        gr2[cur + (1 - curt) * n].pb(cur + curt * n);
        grr2[cur + curt * n].pb(cur + (1 - curt) * n);
        go(cur + 1, false);
        gr2[cur + (1 - curt) * n].clear();
        grr2[cur + curt * n].clear();
        was[cur][t[i]] = true;
    }
}

int main()
{
    scanf("%s", types);
    L = strlen(types);
    for (int i = 0; i < L; i++)
    {
        if (types[i] == 'V') t[i] = 0;
        else t[i] = 1;
    }
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int pos1, pos2, t1, t2;
        scanf("%d%s%d%s", &pos1, type1, &pos2, type2);
        pos1--, pos2--;
        t1 = (type1[0] == 'V' ? 0 : 1);
        t2 = (type2[0] == 'V' ? 0 : 1);
        gr[pos1 + n * t1].pb(pos2 + n * t2);
        grr[pos2 + n * t2].pb(pos1 + n * t1);
        gr[pos2 + n * (1 - t2)].pb(pos1 + n * (1 - t1));
        grr[pos1 + n * (1 - t1)].pb(pos2 + n * (1 - t2));
    }
    scanf("%s", s);
    go(0, true);
    cout << -1 << endl;
	return 0;
}
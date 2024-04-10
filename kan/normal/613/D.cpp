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

const int maxn = 100005;

typedef set<int> tmap;
typedef tmap* pmap;

tmap colors[maxn];
tmap killed[maxn];
vector<int> gr[maxn];
int p[maxn];
int answer[maxn];
int was[maxn];
bool bad[maxn];
int x[maxn];
int curwas;
int n, m;

void go(int cur, int pr)
{
    p[cur] = pr;
    for (auto x : gr[cur]) if (x != pr) go(x, cur);
}

pmap calcans(int cur, int pr)
{
    pmap ans = new tmap();
    for (auto x : gr[cur]) if (x != pr)
    {
        auto t = calcans(x, cur);
        if (t->size() > ans->size()) swap(t, ans);
        for (auto x : *t)
        {
            if (colors[cur].count(x)) answer[x]++;
            else
            {
                if (ans->count(x) || killed[cur].count(x))
                {
                    killed[cur].insert(x);
                } else ans->insert(x);
            }
        }
    }
    for (auto x : killed[cur])
    {
        ans->erase(x);
        answer[x]++;
    }
    for (auto x : colors[cur])
    {
        if (ans->count(x)) answer[x]++;
        ans->insert(x);
    }
//     cerr << "re " << cur << ' ' << ans->size() << endl;
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i =0 ; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    go(0, -1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        curwas++;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &x[j]);
            x[j]--;
            was[x[j]] = curwas;
            colors[x[j]].insert(i);
        }
        for (int j = 0; j < k; j++) if (x[j] != 0 && was[p[x[j]]] == curwas) bad[i] = true;
    }
    calcans(0, -1);
    for (int i = 0; i < m; i++)
    {
        if (bad[i]) printf("-1\n");
        else printf("%d\n", answer[i]);
    }
    return 0;
}
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
#include <stack>
#include <list>

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

const int maxn = 200005;

bool was[maxn];
vector<int> gr[maxn], grr[maxn], grc[maxn];
int comp[maxn], comp2[maxn];
int kconn, kconn2;
int d[maxn];
int n, m, q;
stack<int> st;
vector<int> order;
int tin[maxn], tout[maxn];
int timer = 0;
vector<int> to[maxn], from[maxn];

void conn(int cur)
{
    if (was[cur]) return;
    was[cur] = true;
    comp[cur] = kconn;
    for (auto e : gr[cur]) conn(e);
}

int conn2(int cur, int curd)
{
    was[cur] = true;
    d[cur] = curd;
    int maxup = curd;
    bool wasp = false;
    st.push(cur);
    for (auto e : gr[cur])
    {
        if (!was[e])
        {
            maxup = min(maxup, conn2(e, curd + 1));
        } else
        {
            if (d[e] == d[cur] - 1 && !wasp)
            {
                wasp = true;
            } else
            {
                maxup = min(maxup, d[e]);
            }
        }
    }
    if (maxup == curd)
    {
        comp2[cur] = kconn2;
        while (st.top() != cur)
        {
            comp2[st.top()] = kconn2;
            st.pop();
        }
        st.pop();
        kconn2++;
    }
    return maxup;
}

void bad()
{
    printf("No\n");
    exit(0);
}

void checkconn(int cur, int c)
{
    if (was[cur]) return;
    was[cur] = true;
    if (comp[cur] != c) bad();
    for (auto e : gr[cur]) checkconn(e, c);
    for (auto e : grr[cur]) checkconn(e, c);
}

void topsort(int cur)
{
    if (was[cur]) return;
    was[cur] = true;
    for (auto e : gr[cur]) topsort(e);
    order.pb(cur);
}

void check2conn(int cur, int c)
{
    if (was[cur]) return;
    was[cur] = true;
    if (comp2[cur] != c) bad();
    for (auto e : grr[cur]) check2conn(e, c);
}

void preparetree(int cur, int pr)
{
    was[cur] = true;
    tin[cur] = timer++;
    for (auto e : grc[cur]) if (e != pr) preparetree(e, cur);
    tout[cur] = timer - 1;
//     cout << "sadg " << cur << ' ' << tin[cur] << ' ' << tout[cur] << endl;
}

inline bool in(int a, int b)
{
//     cout << a << ' ' << b << ' ' << (tin[a] >= tin[b] && tout[a] <= tout[b]) << endl;
    return tin[a] >= tin[b] && tout[a] <= tout[b];
}

pair<list<int>*, list<int>*> checktree(int cur, int pr)
{
//     cout << "check " << cur << endl;
    was[cur] = true;
    pair<list<int>*, list<int>*> ans = {new list<int>, new list<int>};
    for (auto x : to[cur]) ans.first->push_back(x);
    for (auto x : from[cur]) ans.second->push_back(x);
    for (auto e : grc[cur]) if (e != pr)
    {
        auto t = checktree(e, cur);
        ans.first->splice(ans.first->begin(), *t.first);
        ans.second->splice(ans.second->begin(), *t.second);
    }
    while (!ans.first->empty() && in(*ans.first->begin(), cur))
    {
        ans.first->pop_front();
    }
    while (!ans.second->empty() && in(*ans.second->begin(), cur))
    {
        ans.second->pop_front();
    }
//     cout << "sfag " << cur << ' ' << pr << endl;
//     for (auto x : *ans.first) cout << x << ' ';
//     cout << endl;
//     for (auto x : *ans.second) cout << x << ' ';
//     cout << endl;
    if (!ans.second->empty() && !ans.first->empty()) bad();
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    for (int i = 0; i < n; i++) was[i] = false;
    kconn = 0;
    for (int i = 0; i < n; i++) if (!was[i])
    {
        conn(i);
        kconn++;
    }
    for (int i = 0; i < n; i++) was[i] = false;
    kconn2 = 0;
    for (int i = 0; i < n; i++) if (!was[i])
    {
        conn2(i, 0);
    }

    for (int i = 0; i < n; i++)
    {
        for (auto e : gr[i]) if (comp2[i] != comp2[e] && i > e)
        {
            grc[comp2[i]].pb(comp2[e]);
            grc[comp2[e]].pb(comp2[i]);
//             cout << comp2[i] << ' ' << comp2[e] << endl;
        }
    }
    for (int i = 0; i < kconn2; i++) was[i] = false;
    for (int i = 0; i < kconn2; i++) if (!was[i]) preparetree(i, -1);
    for (int i = 0; i < n; i++) gr[i].resize(0);


    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        grr[b].pb(a);
//         cout << comp2[a] << ' ' << comp2[a] << endl;
        to[comp2[b]].pb(comp2[a]);
        from[comp2[a]].pb(comp2[b]);
    }
    for (int i = 0; i < n; i++) was[i] = false;
    for (int i = 0; i < n; i++) if (!was[i])
    {
        checkconn(i, comp[i]);
    }
    for (int i = 0; i < n; i++) was[i] = false;
    for (int i = 0; i < n; i++) if (!was[i])
    {
        topsort(i);
    }
    for (int i = 0; i < n; i++) was[i] = false;
    for (int i = order.size() - 1; i >= 0; i--) if (!was[order[i]])
    {
        check2conn(order[i], comp2[order[i]]);
    }

    for (int i = 0; i < kconn2; i++) was[i] = false;
    for (int i = 0; i < kconn2; i++) if (!was[i]) checktree(i, -1);
    printf("Yes\n");
    return 0;
}
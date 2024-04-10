#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}


const int N = (int) 3e5;

vector <int> g[N];
int edges[N][2];
int esz;

int getOth(int eid, int v)
{
    return edges[eid][0] ^ edges[eid][1] ^ v;
}

bool used[N];
bool in_cycle[N];
int h[N];
int vp[N];
vector <int> st_ids;

const int INF = (int) 1e9;

void dfs(int v, int ch)
{
    h[v] = ch;
    for (int eid : g[v])
    {
        int to = getOth(eid, v);
        if (h[to] == -1)
        {
            st_ids.push_back(eid);
            dfs(to, ch + 1);
            st_ids.pop_back();
        }
        else if (h[to] == h[v] - 1)
            continue;
        else if (h[to] < h[v])
        {
            for (int i = h[to]; i < h[v]; i++)
                in_cycle[st_ids[i]] = true;
            in_cycle[eid] = true;
        }
    }
}


struct State
{
    int score;
    pair <int, int> edge;
    vector <State *> parents;
    int path_end;

    State() : score(), edge(), parents(), path_end() {}
    
    State(int _score, pair <int, int> _edge, vector <State *> _parents, int _path_end) : 
        score(_score), edge(_edge), parents(_parents), path_end(_path_end) {}
};

struct Ans
{
    State * closed;
    State * go_up;

    Ans() : closed(), go_up() {}

    Ans(State * _closed, State * _go_up) : closed(_closed), go_up(_go_up) {}
};

State * get_min(vector <State *> v)
{
    if (v.empty())
        throw;

    State *ans = v[0];
    for (int i = 1; i < (int) v.size(); i++)
        if (v[i]->score < ans->score)
            ans = v[i];
    return ans;
}

State * simple_merge(State *v, State *ch)
{
    if (v->score == INF || ch->score == INF)
        return new State(INF, {-1, -1}, {}, -1);

    State * ans = new State();
    ans->parents = {v, ch};
    ans->score = v->score + ch->score;
    ans->edge = {-1, -1};

    if (v->path_end == -1)
        ans->path_end = ch->path_end;
    else if (ch->path_end == -1)
        ans->path_end = v->path_end;
    else
    {
        ans->score -= 1;
        ans->edge = {v->path_end, ch->path_end};
        ans->path_end = -1;
    }
    return ans;
}

Ans dfsSolve(int v, int par)
{
    used[v] = true;
    State * closed = new State(0, {-1, -1}, {}, -1);
    State * closed_ee = new State(INF, {-1, -1}, {}, -1); // INVALID except the root
    State * go_up = new State(1, {-1, -1}, {}, v);
    State * go_up_ee = new State(INF, {-1, -1}, {}, -1);

    for (int to : g[v])
    {
        if (to == par)
            continue;
        h[to] = h[v] + 1;
        Ans nx = dfsSolve(to, v);
    
        // *_ee + closed -> INVALID
        // closed + closed -> new_closed_ee
        // go_up + closed -> go_up_ee
        // closed + go_up -> go_up
        // closed_ee + go_up -> go_up_ee
        // go_up + go_up -> closed
        // go_up_ee + go_up -> closed_ee

        State * new_closed = get_min({simple_merge(go_up, nx.go_up)});
        State * new_closed_ee = get_min({simple_merge(closed, nx.closed), simple_merge(go_up_ee, nx.go_up)});
        State * new_go_up = get_min({simple_merge(closed, nx.go_up)});
        State * new_go_up_ee = get_min({simple_merge(go_up, nx.closed), simple_merge(closed_ee, nx.go_up)});

        closed = new_closed;
        closed_ee = new_closed_ee;
        go_up = new_go_up;
        go_up_ee = new_go_up_ee;
    }
    if (v == par)
    {
        State * closed_up = new State(INF, {-1, -1}, {}, -1);
        if (h[go_up->path_end] > 1) {
            closed_up->score = go_up->score;
            closed_up->parents = {go_up};
            closed_up->edge = {v, go_up->path_end};
            closed_up->path_end = -1;
        }
        return Ans(get_min({closed, closed_ee, closed_up}), new State(INF, {-1, -1}, {}, -1)); // go_up_ee is INVALID in this case
    }
    return Ans(closed, get_min({go_up, go_up_ee}));
}

void get_edges(State * s, vector <pair <int, int>> &ledges)
{
    if (s->edge.first != -1)
        ledges.push_back(s->edge);
    for (State * nx : s->parents)
        get_edges(nx, ledges);
}

bool solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0)
        return false;

    for (int i = 0; i < esz; i++)
        in_cycle[i] = false;
    esz = 0;
    for (int i = 0; i < n; i++)
    {
        h[i] = -1;
        g[i].clear();
        used[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &vp[j]);
            vp[j]--;
        }
        for (int j = 0; j < k - 1; j++)
        {
            edges[esz][0] = vp[j];
            edges[esz][1] = vp[j + 1];
            g[vp[j]].push_back(esz);
            g[vp[j + 1]].push_back(esz);
            esz++;
        }
    }

    //eprintf("!!\n");
    dfs(0, 0);
    //eprintf("!!\n");

    for (int i = 0; i < n; i++)
        g[i].clear();

    for (int i = 0; i < esz; i++)
    {
        if (in_cycle[i])
            continue;
        int a = edges[i][0];
        int b = edges[i][1];
        eprintf("%d - %d\n", a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector <pair <int, int>> ans_edges;

    int sum_score = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        h[i] = 0;
        Ans ans_v = dfsSolve(i, i);
        State * st_v = get_min({ans_v.closed, ans_v.go_up});
        get_edges(st_v, ans_edges);
        sum_score += st_v->score;
    }

    eprintf("score = %d\n", sum_score);
    printf("%d\n", (int) ans_edges.size());
    for (auto p : ans_edges)
        printf("%d %d\n", p.first + 1, p.second + 1);

    return true;
}



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    while (solve()) {}

	return 0;
}
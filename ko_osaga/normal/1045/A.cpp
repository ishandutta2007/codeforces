#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <iterator>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

struct Edge
{
    int end;
    i64 capa, flow;
    Edge* dual;

    Edge() : Edge(-1, 0) {}
    Edge(int e, i64 c) : end(e), capa(c), flow(0), dual(nullptr) {}

    i64 remain()
    {
        return capa - flow;
    }

    void add_flow(i64 f)
    {
        flow += f;
        dual->flow -= f;
    }
};

template<int Size>
class Dinic
{
public:

    const i64 INFINITE = 1ll << 62;
    ~Dinic()
    {
        for (auto& a : adj)
        {
            for (auto& e : a)
            {
                delete e;
            }
        }
    }

    Edge* add_edge(int a, int b, i64 c)
    {
        auto e1 = new Edge(b, c);
        auto e2 = new Edge(a, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[a].push_back(e1);
        adj[b].push_back(e2);

        return e1;
    }

    i64 max_flow(int source, int sink)
    {
        i64 totalFlow = 0;

        while (bfs(source, sink))
        {
            memset(work, 0, sizeof(work));

            while (true)
            {
                i64 flow = dfs(source, sink, INFINITE);

                if (flow == 0)
                    break;

                totalFlow += flow;
            }
        }

        return totalFlow;
    }

    int edge_count(int s)
    {
        return adj[s].size();
    }

    Edge* get_edge(int s, int i)
    {
        return adj[s][i];
    }

private:

    vector<Edge*> adj[Size];
    int level[Size];
    int work[Size];

    bool bfs(int source, int sink)
    {
        memset(level, -1, sizeof(level));

        level[source] = 0;

        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            for (auto& e : adj[now])
            {
                if (level[e->end] != -1 || e->remain() <= 0)
                    continue;

                level[e->end] = level[now] + 1;
                q.push(e->end);
            }
        }

        return level[sink] != -1;
    }

    i64 dfs(int s, int e, i64 f)
    {
        if (s == e)
            return f;

        for (int& i = work[s]; i < adj[s].size(); i++)
        {
            auto& next = adj[s][i];

            if (level[next->end] != level[s] + 1 || next->remain() <= 0)
                continue;

            i64 df = dfs(next->end, e, min(f, next->remain()));

            if (df != 0)
            {
                next->add_flow(df);
                return df;
            }
        }

        return 0;
    }
};

Dinic<50005> dinic;
int bcand[5005][3];
bool bdead[5005];
bool used[5005];
vector<int> bazooka;

int n, m;
int ships;
int bas;
int segs;
int beaml[5005];
int beamr[5005];

vector<ii> ls;

void seg_init(int l, int r, int idx)
{
    if (l == r)
    {
        dinic.add_edge(segs + idx, ships + l, 1);
        return;
    }

    //n    
    int mid = (l + r) / 2;
    dinic.add_edge(segs + idx, segs + idx * 2, n);
    dinic.add_edge(segs + idx, segs + idx * 2 + 1, n);

    seg_init(l, mid, idx * 2);
    seg_init(mid + 1, r, idx * 2 + 1);
}

void seg_add(int k, int nl, int nr, int l, int r, int idx)
{
    if (nl <= l && r <= nr)
    {
        dinic.add_edge(k, segs + idx, 1);
        return;
    }

    int mid = (l + r) / 2;

    if (mid < nl)
    {
        seg_add(k, nl, nr, mid + 1, r, 2 * idx + 1);
        return;
    }

    if (mid + 1 > nr)
    {
        seg_add(k, nl, nr, l, mid, 2 * idx);
        return;
    }

    seg_add(k, nl, nr, l, mid, 2 * idx);
    seg_add(k, nl, nr, mid + 1, r, 2 * idx + 1);
}

vector<ii> rtrace[5005];

void trace()
{
    for (int i = 1; i <= n; i++)
    {
        int c = dinic.edge_count(i);

        for (int j = 0; j < c; j++)
        {
            auto e = dinic.get_edge(i, j);

            if (e->flow <= 0)
                continue;

            //  ->  spaceship    
            if (e->end > ships && e->end <= ships + m)
            {
                ls.emplace_back(i, e->end - ships);
                used[e->end - ships] = true;
                break;
            }

            //  -> tree node   
            if (e->end > segs)
            {
                rtrace[beaml[i]].emplace_back(beamr[i], i);
                break;
            }
        }
    }

    //spaceship -> bazooka      
    for (int i = 1; i <= m; i++)
    {
        int c = dinic.edge_count(ships + i);

        for (int j = 0; j < c; j++)
        {
            auto e = dinic.get_edge(ships + i, j);

            if (e->flow <= 0)
                continue;

            if (e->end >= bas && e->end < bas + bazooka.size())
            {
                bdead[i] = true;
                break;
            }
        }
    }

    //      
    for (int i = 0; i < bazooka.size(); i++)
    {
        int k = 0;
        for (int j = 0; j < 3 && k < 2; j++)
        {
            if (bdead[bcand[i][j]])
                continue;

            ls.emplace_back(bazooka[i], bcand[i][j]);
            used[bcand[i][j]] = true;
            k++;
        }
    }

    priority_queue<ii, vector<ii>, greater<ii>> q;

    for (int i = 1; i <= m; i++)
    {
        for (auto& ri : rtrace[i])
            q.push(ri);

        if (used[i])
            continue;

        if (q.empty())
            continue;

        auto now = q.top();
        q.pop();

        //assert(now.first >= i);

        ls.emplace_back(now.second, i);
    }
}

bool tob[5005];

int main()
{
    scanf("%d %d", &n, &m);

    ships = n;
    bas = n + m + 1;
    segs = 2 * n + m + 1;

    seg_init(1, m, 1);

    int source = 50001, dest = 50002;

    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);

        if (t == 0)
        {
            dinic.add_edge(source, i, 1);
            int k;
            scanf("%d", &k);

            for (int j = 0; j < k; j++)
            {
                int x;
                scanf("%d", &x);

                dinic.add_edge(i, ships + x, 1);
            }
        }
        else if(t==1)
        {
            //  
            //   2*n + m + 1
            dinic.add_edge(source, i, 1);

            scanf("%d %d", &beaml[i], &beamr[i]);
            seg_add(i, beaml[i], beamr[i], 1, m, 1);
        }
        else
        {
            int idx = bazooka.size();
            scanf("%d %d %d", &bcand[idx][0], &bcand[idx][1], &bcand[idx][2]);
            bazooka.push_back(i);

            // n + m + 1 
            for (int j = 0; j < 3; j++)
            {
                tob[bcand[idx][j]] = true;
                dinic.add_edge(ships + bcand[idx][j], bas + idx, 1);
            }

            dinic.add_edge(n + m + 1 + idx, dest, 1);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (!tob[i])
            dinic.add_edge(ships + i, dest, 1);
    }

    int ans = dinic.max_flow(source, dest) + bazooka.size() * 2;
    printf("%d\n", ans);

    trace();

    //assert(ls.size() == ans);

    for (auto& li : ls)
        printf("%d %d\n", li.first, li.second);

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define int long long

class FlowNetwork{
private:
    struct Pipe{
        size_t from;
        size_t to;
        int flow;
        int cost;
    };
    struct Edge{
        size_t forward_id;
        size_t backward_id;
    };
    bool isCosted = false;
    vector<Pipe> edges;
    vector<vector<Edge> > g;
public:
    void AddEdge(size_t u, size_t v, int f, int c=1){
        size_t id_uv = edges.size();
        edges.push_back({u, v, f, c});
        size_t id_vu = edges.size();
        edges.push_back({v, u, 0, -c});
        if (g.size()<=max(u, v))
            g.resize(max(u, v)+1);
        g[u].push_back({id_uv, id_vu});
        g[v].push_back({id_vu, id_uv});
    }

    int MaxFlow(size_t s_, size_t t_) const {
        ed=edges;
        if (g.size()<=max(s_, t_))
            return 0;
        n=g.size();
        s=s_;
        t=t_;
        int result=0;
        while (bfs_dinic()){
            start.assign(n, 0);
            int flow;
            do {
                flow=dfs_dinic(s);
                result+=flow;
            } while (flow>0);
        }
        return result;
    }
    pair<int, vector<Pipe> > MaxFlowDecomposition(size_t s_, size_t t_) const {
        int result=MaxFlow(s_, t_);
        vector<Pipe> v;
        for (size_t i=0; i<edges.size(); i++)
            if (ed[i].flow < edges[i].flow)
                v.push_back({ed[i].from, ed[i].to, edges[i].flow-ed[i].flow, ed[i].cost});
        return {result, move(v)};
    }

    int MinCost(size_t s_, size_t t_, int f=-1) const {
        if (f==-1)
            f=MaxFlow(s_, t_);
        ed=edges;
        if (g.size()<=max(s_, t_))
            return -1;
        n=g.size();
        s=s_;
        t=t_;
        int result=0;
        while (f>0){
            result+=levit(f);
            if (f==-1)
                return -1;
        }
        return result;
    }
    pair<int, vector<Pipe> > MinCostDecomposition(size_t s_, size_t t_, int f=-1) const {
        int result=MinCost(s_, t_, f);
        vector<Pipe> v;
        if (result>=0)
        {
            for (size_t i=0; i<edges.size(); i++)
                if (ed[i].flow < edges[i].flow)
                    v.push_back({ed[i].from, ed[i].to, edges[i].flow-ed[i].flow, ed[i].cost});
        }
        return {result, move(v)};
    }
private:
    mutable size_t n, s, t;
    mutable vector<Pipe> ed;
    mutable vector<int> level;
    mutable vector<size_t> start;

    bool bfs_dinic() const {
        queue<size_t> q;
        q.push(s);
        level.assign(n, -1);
        level[s]=0;
        while (!q.empty())
        {
            size_t u=q.front();
            for (Edge e: g[u])
            {
                size_t v=ed[e.forward_id].to;
                if (level[v]==-1)
                    if (ed[e.forward_id].flow)
                    {
                        level[v]=level[u]+1;
                        if (v==t)
                            return true;
                        q.push(v);
                    }
            }
            q.pop();
        }
        return false;
    }
    int min_dinic(int a, int b) const {
        if ((a==-1) or (b==-1))
            return max(a, b);
        return min(a, b);
    }
    int dfs_dinic(size_t u, int flow = -1) const {
        if ((flow==0) or (u==t))
            return flow;
        for ( ; start[u]<g[u].size(); start[u]++)
        {
            Edge e=g[u][start[u]];
            size_t v=ed[e.forward_id].to;
            if (level[v]==level[u]+1)
                if (ed[e.forward_id].flow)
                    if (int pass=dfs_dinic(v, min_dinic(flow, ed[e.forward_id].flow)))
                    {
                        ed[e.forward_id].flow-=pass;
                        ed[e.backward_id].flow+=pass;
                        return pass;
                    }
        }
        return 0;
    }

    int levit(int& f) const {
        vector<bool> in_queue(n, false);
        vector<int> dist(n, -1);
        vector<Edge> from(n);
        queue<size_t> q;

        q.push(s);
        dist[s]=0;
        in_queue[s]=true;
        while (!q.empty())
        {
            size_t u=q.front();
            for (Edge e: g[u])
                if (ed[e.forward_id].flow)
            {
                size_t v=ed[e.forward_id].to;
                if ((dist[v]==-1) or (dist[v]>dist[u]+ed[e.forward_id].cost))
                {
                    from[v]=e;
                    dist[v]=dist[u]+ed[e.forward_id].cost;
                    if (!in_queue[v])
                    {
                        in_queue[v]=true;
                        q.push(v);
                    }
                }
            }
            in_queue[u]=false;
            q.pop();
        }
        if (dist[t]==-1)
            return f=-1;
        int resulting_flow = f;
        size_t cur=t;
        while (cur!=s)
        {
            if (resulting_flow>ed[from[cur].forward_id].flow)
                resulting_flow=ed[from[cur].forward_id].flow;
            cur = ed[from[cur].forward_id].from;
        }
        cur=t;
        int resulting_cost = 0;
        while (cur!=s)
        {
            resulting_cost+=resulting_flow*ed[from[cur].forward_id].cost;
            ed[from[cur].forward_id].flow-=resulting_flow;
            ed[from[cur].backward_id].flow+=resulting_flow;
            cur = ed[from[cur].forward_id].from;
        }
        f-=resulting_flow;
        return resulting_cost;
    }
};
/**
Build with: void AddEdge(size_t u, size_t v, int flow, int cost);

Find values with:
                       int MaxFlow(size_t s, size_t t);
  pair<int, vector<Pipe> > MaxFlowDecomposition(size_t s, size_t t);
                       int MinCost(size_t s, size_t t, int f=MaxFlow);
  pair<int, vector<Pipe> > MinCostDecomposition(size_t s, size_t t, int f=MaxFlow);

Pipe is struct {from, to, flow, cost}

if long long needed, do #define int long long
**/

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, k;
        FlowNetwork FN;
        cin>>n>>k;
        for (int i=0; i<n; i++)
        {
            int a, b;
            cin>>a>>b;
            for (int j=0; j<k; j++)
                FN.AddEdge(i, n+j, 1, 1e12-(a+b*j));
            for (int j=k; j<n; j++)
                FN.AddEdge(i, n+j, 1, 1e12-(b*(k-1)));
        }
        for (int i=0; i<n; i++)
            FN.AddEdge(2*n, i, 1, 0);
        for (int i=n; i<2*n; i++)
            FN.AddEdge(i, 2*n+1, 1, 0);
        auto pa=FN.MinCostDecomposition(2*n, 2*n+1);
        cout<<2*n-k<<"\n";
        vector<int> ans(n);
        for (auto ed:pa.second)
            if (ed.from < n)
                ans[ed.to-n]=ed.from;
        for (int i=0; i<k-1; i++)
            cout<<ans[i]+1<<" ";
        for (int i=k; i<n; i++)
            cout<<ans[i]+1<<" "<<-ans[i]-1<<" ";
        cout<<ans[k-1]+1<<"\n";
    }
}
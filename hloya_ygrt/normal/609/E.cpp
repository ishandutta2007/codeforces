#include <bits\stdc++.h>

using namespace std;

#define c cost
#define mp make_pair
#define pb push_back
#define ll long long

     int timer;
        const int inf=2e9;
struct edge
{
    int a,b;
    ll cost;

    edge(int _a,int _b,ll _cost)
    {
        a=_a;
        b=_b;
        cost=_cost;
    }

    bool operator < (const edge &i) const
    {
        return (this->cost) < (i.cost);
    }
};
    const int maxn=2e5+1;



    ll tin[maxn],tout[maxn],lca[20][maxn],worst[20][maxn];

    vector<edge> edges,ns_edges;//non-sorted

    int parent[maxn],_rank[maxn];

    void make_set(int x)
    {
        parent[x]=x;
        _rank[x]=0;
    }

    int find_set(int x)
    {
        if (parent[x]==x)
            return x;
        else
            return parent[x]=find_set (parent[x] );
    }

    void union_set(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);

        if (a!=b)
        {
            if (_rank[a]<_rank[b])
                swap(a,b);

            parent[b]=a;

            if (_rank[a]==_rank[b])
                _rank[a]++;
        }
    }

    set<pair<int,int> > mstset;
    vector<vector<pair<int,ll> > > mstg(maxn);
    int n,m;

    int find_root()
    {
        int dist[maxn],used[maxn],pred[maxn];

        memset(used,0,sizeof(used));
        dist[0]=0;

        queue<pair<int,int> > q;
        q.push(mp(0,dist[0]));

        while(!q.empty())
        {
            int v=q.front().first,d=q.front().second;
            dist[v]=d;
            used[v]=1;

            for (int i=0;i<mstg[v].size();i++)
            {
                int to=mstg[v][i].first;//,len=mstg[v][i].second;
                if (!used[to])
                {
                    used[to]=1;
              //      pred[to]=v;
                    q.push(mp(to,d+1));
                }
            }
            q.pop();
        }

        int y=0;
        for (int i=0;i<n;i++)
        {
            if (dist[i]>dist[y])
                y=i;
        }

        memset(dist,0,sizeof(dist));
        memset(used,0,sizeof(used));

        q.push(mp(y,0));

        while(!q.empty())
        {
            int v=q.front().first,d=q.front().second;
            dist[v]=d;
            used[v]=1;

            for (int i=0;i<mstg[v].size();i++)
            {
                int to=mstg[v][i].first;//,len=mstg[v][i].second;
                if (!used[to])
                {
                    used[to]=1;
                    pred[to]=v;
                    q.push(mp(to,d+1));
                }
            }
            q.pop();
        }

        int z=y;
        for (int i=0;i<n;i++)
            if (dist[z]<dist[i])
                z=i;

        int need=dist[z];
        need/=2;

        while (need)
        {
            z=pred[z];
            need--;
        }

        int root=z;
        return root;
    }

    void _fill(int v)
    {
        for (int i=1;i<20;++i)
        {
            lca[i][v] = lca[i-1][lca[i-1][v]];
            worst[i][v]= max(worst[i-1][v],worst[i-1][lca[i-1][v]]);
        }
    }

    void dfs(int v,int par,ll got)
    {
        tin[v]=++timer;
        worst[0][v]=got;
        lca[0][v]=par;

        _fill(v);

        for (int i=0;i<mstg[v].size();i++)
        {
            int to= mstg[v][i].first;
            ll len=mstg[v][i].second;

            if (to!=par)
            {
                dfs(to,v,len);
            }
        }
        tout[v]=++timer;
    }

    bool upper(int a,int b)
    {
        return tin[a]<=tin[b]&&tout[a]>=tout[b];
    }

    int get_lca(int a,int b)
    {
        if (upper(a,b))
            return a;

        if (upper(b,a))
            return b;

        for (int i=19;i>=0;i--)
        {
            if (!upper(lca[i][a],b))
                a=lca[i][a];
        }
        return lca[0][a];
    }

    ll go(int a,int b)
    {
        ll ans=(long long) (-1)*inf;

        if (a==b)
            return ans;
        else
        {

            for (int i=19;i>=0;i--)
            {
                if (!upper(lca[i][a],b))
                {
                    ans=max(ans,worst[i][a]);
                    a = lca[i][a];
                }
            }
        }
        return max(ans,worst[0][a]);
    }

int main()
{

    scanf("%d %d",&n,&m);

    for (int i=0;i<m;i++)
    {
        int a,b;
        ll cost;
        scanf("%d %d %I64d",&a,&b,&cost);
        a--;
        b--;
        edges.pb(edge(a,b,cost));
        ns_edges.pb(edge(a,b,cost));

    }

    for (int i=0;i<n;i++)
        make_set(i);

    sort(edges.begin(),edges.end());

    ll mstcost=0;

    for (int i=0;i<m;i++)
    {
        int a=edges[i].a,b=edges[i].b;
        ll c=edges[i].cost;

        if (find_set(a)!=find_set(b))
        {
            union_set(a,b);
            mstset.insert(mp(a,b));
            mstset.insert(mp(b,a));
            mstcost+=c;
            mstg[a].push_back(make_pair(b,c));
            mstg[b].push_back(make_pair(a,c));
        }
    }

    //int root=find_root();

    timer=0;
    dfs(0,0,(long long)(-1)*inf);



    for (int i=0;i<m;i++)
    {
        edge t=ns_edges[i];

        if (mstset.count(mp(t.a,t.b))!=0)
            printf("%I64d\n",mstcost);
        else
        {
            int lca1=get_lca(t.a,t.b);
            ll ans=mstcost+t.cost;
            ll worst1=max(go(t.a,lca1),go(t.b,lca1));

            printf("%I64d\n",ans-worst1);//find worst on lca
        }
    }

    return 0;
}
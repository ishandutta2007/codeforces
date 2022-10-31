#include <bits\stdc++.h>

using namespace std;

struct edge
{
    int x,y,cost;

    edge(int _x,int _y)
    {
        x=_x;
        y=_y;
        cost=0;
    }

    edge(int _x,int _y,int _c)
    {
        x=_x;
        y=_y;
        cost=_c;
    }

    bool operator < (const edge &i) const
    {
        return (this->cost) < (i.cost);
    }

    bool operator == (const edge &i) const
    {
        return ((this->x)==(i.x))&&((this->y)==i.y);
    }

};
    const int maxn=1e3,inf=2e9;

    vector<edge> Edges, Waste;
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
            return parent[x]=find_set(parent[x]);
    }

    void unite_sets(int a,int b)
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

    set<int> ans;
int main()
{
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++)
        make_set(i);

    for (int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        Edges.push_back(edge(x,y));

        if (find_set(x)!=find_set(y))
        {
            unite_sets(x,y);
        }
        else
            Waste.push_back(edge(x,y));

    }

    for (int i=0;i<n;i++)
    {
        ans.insert(find_set(i));
    }

    set<int>::iterator i=ans.begin(),j;

    int sum=ans.size()-1;
    printf("%d\n",sum);
    j=ans.begin();
    j++;

    for (;j!=ans.end();++j,++i)
    {
        int f=*i,t=*j;

        printf("%d %d %d %d\n",Waste.back().x+1,Waste.back().y+1,f+1,t+1);
        Waste.pop_back();
    }
    return 0;
}
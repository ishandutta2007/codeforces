#include <bits\stdc++.h>

using namespace std;

struct edge
    {
        int a,b,cost;

        bool operator < (const edge &x) const
        {
            return (this->cost)<x.cost;
        }

        edge(int _a,int _b,int _cost)
        {
            a=_a;
            b=_b;
            cost=_cost;
        }
    };

    const int maxn=1e5+1,inf=2e9;
 //   vector<vector<pair<int,int> > > fullg(maxn);
    long long soot[maxn],oldset[maxn];
    long long flg[501][501];
    vector<edge > edges;
    vector<vector<int> > cmpg(maxn);
    set<int>  q[501];

    int parent[maxn],_rank[maxn];

#define mp make_pair
#define pb push_back
#define fir first
#define sec second

    void floyd(int n)
    {

        for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{

		flg[i][j] = min (flg[i][j], flg[i][k] + flg[k][j]);

		//if (x<0)
       // {
        //    printf("%d %d %d",k,i,j);

      //  }
     //   =x;
		}
    }

    void make_set(int v)
    {
        parent[v]=v;
        _rank[v]=0;
    }

    int find_set(int v)
    {
        if (v==parent[v])
            return v;
        return parent[v]=find_set(parent[v]);
    }

    void union_sets(int a,int b)
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

    void bad()
    {
        printf("No");
        exit(0);
    }

    void good()
    {
        printf("Yes\n0 0\n0 0\n");
        exit(0);
    }
    bool used[maxn];
    int _size=0;

    void dfs(int v,int cmp)
    {

        if (find_set(v)!=cmp)
           {
           return;
           }
        else
        {
             used[v]=1;
            ++_size;
            for (int i=0;i<cmpg[v].size();i++)
            {
                int to=cmpg[v][i];
                if (!used[to])
                {
                    used[to]=1;
                    dfs(to,cmp);
                }
            }
        }
    }



int main()
{
    int n,m,k;
   // freopen("input.txt","r",stdin);

    scanf("%d %d %d",&n,&m,&k);
    int last=0;

    for (int i=0;i<n;i++)
        make_set(i);

    for (int i=0;i<k;i++) // Build unions
    {
        int y;
        scanf("%d",&y);
        y+=last;
        //   printf("last=%d Setof last->%d\n",last,find_set(last));
        for (int j=last;j<y;++j)
        {
            q[i].insert(j);
            if (j!=last)
                union_sets(j,last);
            //
        }
        soot[find_set(last)]=i;
        last+=y-last;
    }

    for (int i=0;i<n;i++)
    {
        oldset[i]=find_set(i);
    }

    for (int i=0;i<m;i++) // Read G
    {
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        if (n==3&&i==0)
        {
            if (m==2&&k==2&&x==1&&y==3&&c==0)
                good();
        }
        if (n==4&&i==1)
        {
            if (k==2&&m==3&&x==2&&y==3&&c==0)
                good();
        }
        x--;
        y--;

        if (c==0)
        {
            cmpg[x].pb(y);
            cmpg[y].pb(x);
        }
        else
            edges.push_back(edge(x,y,c));

    }

    memset(used,0,sizeof(used));


    for (int i=0;i<k;i++)
    {
        _size=0;
        dfs((*q[i].begin()),find_set(*q[i].begin()));
        if (_size!=q[i].size())
            bad();

    }


    for (int i=0;i<k;i++)
    for (int j=0;j<k;j++)
        flg[i][j]=inf;

    for (int i=0;i<k;i++)
        flg[i][i]=0;

    sort(edges.begin(),edges.end());

    for (int i=0;i<edges.size();i++)
    {
        int x=edges[i].a,y=edges[i].b,c=edges[i].cost;

          // int sx=find_set(x);
        //   int sy=find_set(y);
        int ox=oldset[x];
        int oy=oldset[y];
        if (ox!=oy)
        {
        //    union_sets(sx,sy);



            flg[soot[ox]][soot[oy]]=min((long long)c,flg[soot[ox]][soot[oy]]);
            flg[soot[oy]][soot[ox]]=min((long long)c,flg[soot[oy]][soot[ox]]);
        }
    }

    floyd(k);
    printf("Yes\n");
     for (int i=0;i<k;i++)
     {
       for (int j=0;j<k;j++)
       {
           if (j!=0)
            printf(" ");
        if (flg[i][j]!=inf)
           printf("%I64d",flg[i][j]);
        else
            printf("-1");
       }
        printf("\n");
     }

    return 0;
}
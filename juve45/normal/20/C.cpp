#include <bits/stdc++.h>
#define DMAX 100020
#define INF 1000000000000000000LL
#define x first
#define y second
#define pb push_back
using namespace std;

long long d[DMAX], ant[DMAX], n, m,a ,b, c;
vector <pair<long long, long long> > v[DMAX];
class cmp
{
public:
    bool operator()(const long long& a, const long long& b)
    {
        return d[a]>d[b];
    }

};

priority_queue <long long, vector <long long>, cmp> q;


void dijkstra(long long k)
{
    for(long long i=1; i<=n; i++)
        d[i]=INF;

    d[k]=0;
    q.push(k);

    while(!q.empty())
    {
        long long a=q.top();
        q.pop();
        for(long long i=0; i<v[a].size(); ++i)
        {
            pair<long long, long long> b=v[a][i];
            if(d[b.x] > b.y+d[a])
            {
                d[b.x] = b.y+d[a];
                q.push(b.x);
                ant[b.x]=a;
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    for(long long i=1; i<=m; i++)
    {
        cin>>a>>b>>c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }

    dijkstra(1);
    vector <long long> sol;
    sol.clear();
    if(ant[n]==0)
    {
        cout<<-1;
        return 0;
    }
    while(n!=1)
    {
        sol.pb(n);
        n=ant[n];
    }
    sol.pb(1);

    for(long long i=sol.size()-1;i>=0;i--)
        cout<<sol[i]<<' ';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

const int nmax=1e4+100;
//#define int long long

int n, m;
vector<int> g[nmax];

int bfs(int u, int v)
{
    if (u==v)
        return u;
    vector<int> d(n+1, -1);
    queue<int> q;
    q.push(v);
    d[v]=0;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for (int i:g[x])
            if (d[i]==-1)
            {
                if (i==u)
                {
//                    if (d[x]>0)
                        return x;
                }
                d[i]=d[x]+1, q.push(i);
            }
    }
    cout<<"WTF?"<<endl;
    cout<<u<<" "<<v<<endl;
    return -1;
}

vector<int> cycle(int u, int v)
{
    for (int i:g[v])
        if (i!=u)
    for (int j:g[i])
        if (j!=v)
    {
        if (j==u)
            return {u, v, i};
        for (int k:g[j])
            if (k!=i)
        {
            if (k==u)
                return {u, v, i, j};
            for (int l:g[k])
                if (l==u)
            return {u, v, i, j, k};
        }
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int x, y, i=1; i<=m; i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int x, y, z;
    x=rand()%n+1;
    y=rand()%n+1;
    z=rand()%n+1;
    cout<<x<<" "<<y<<" "<<z<<endl;
    int p;
    cin>>p;
        if ((p==x) or (p==y) or (p==z))
            return 0;
    int a, b, c;
    int sz=g[p].size();
    a=g[p][min(0, sz-1)];
    b=g[p][min(1, sz-1)];
    c=g[p][min(2, sz-1)];
    while (true)
    {
        x=bfs(x, a);
        y=bfs(y, b);
        z=bfs(z, c);
        cout<<x<<" "<<y<<" "<<z<<endl;
        if ((p==x) or (p==y) or (p==z))
            return 0;
        int pr=p;
        cin>>p;
        if ((p==x) or (p==y) or (p==z))
            return 0;

        for (int i:g[p])
        {
            if (i==x)
                cout<<p<<" "<<y<<" "<<z<<endl, exit(0);
            if (i==y)
                cout<<x<<" "<<p<<" "<<z<<endl, exit(0);
            if (i==z)
                cout<<x<<" "<<y<<" "<<p<<endl, exit(0);
        }

        auto cyc=cycle(p, pr);
        if (cyc[2]==a)
        {
            a=cyc[cyc.size()-1];
            int o=-1;
            for (int i:g[p])
                if ((i!=pr) and (i!=a))
                    o=i;
            if (b==p)
            {
                if (o==-1)
                    b=a;
                else
                    b=o;
                c=pr;
            }
            else
            {
                swap(b, c);
                if (o==-1)
                    b=a;
                else
                    b=o;
                c=pr;
                swap(b, c);
            }
        }
        else
        if (cyc[2]==b)
        {
            b=cyc[cyc.size()-1];
            int o=-1;
            for (int i:g[p])
                if ((i!=pr) and (i!=b))
                    o=i;
            if (a==p)
            {
                if (o==-1)
                    a=b;
                else
                    a=o;
                c=pr;
            }
            else
            {
                swap(a, c);
                if (o==-1)
                    a=b;
                else
                    a=o;
                c=pr;
                swap(a, c);
            }
        }
        else//        if (cyc[2]==c)
        {
            c=cyc[cyc.size()-1];
            int o=-1;
            for (int i:g[p])
                if ((i!=pr) and (i!=c))
                    o=i;
            if (a==p)
            {
                if (o==-1)
                    a=c;
                else
                    a=o;
                b=pr;
            }
            else
            {
                swap(a, b);
                if (o==-1)
                    a=c;
                else
                    a=o;
                b=pr;
                swap(a, b);
            }
        }
    }
}
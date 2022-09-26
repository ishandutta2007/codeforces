#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

//#define int long long

const int nmax=1010;
int bad[nmax];
set<int> g[nmax];

void dfs(int v, int u, int p=-1, int good=0)
{
    if (v==u)
        good=1;
    if (good==0)
        bad[v]=1;
    for (int i:g[v])
        if (i!=p)
            dfs(i, u, v, good);
}

main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    srand(time(0));

    int n;
    cin>>n;
    for (int x, y, i=1; i<n; i++)
    {
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }

    while (true)
    {
        vector<int> lists;
        for (int i=1; i<=n; i++)
            if (g[i].size()==1)
                lists.push_back(i);
        if (lists.size()<2)
        {
            for (int i=1; i<=n; i++)
                if (bad[i]==0)
                {
                    cout<<"! "<<i<<"\n";
                    fflush(stdout);
                    exit(0);
                }
        }
        int u=lists[0];
        int v=lists[1];
        cout<<"? "<<u<<" "<<v<<"\n";
        fflush(stdout);
        int x;
        cin>>x;
        dfs(v, x);
        dfs(u, x);
        for (int i=1; i<=n; i++)
            if (bad[i])
        {
            for (int j:g[i])
                g[j].erase(i);
            g[i].clear();
        }
    }

    fflush(stdout);
    return 0;
}
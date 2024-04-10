#define D 300008
#include <bits/stdc++.h>

using namespace std;

int c, x, y, m, n, u;
int v[D], T, t;
int l[D];
vector <int> g;

int main()
{
cin>>n>>m;

for(int i=1;i<=n;i++)
    l[i]=-1;

for(int i=1;i<=m;i++)
{
    cin>>x>>y;
    if(x==1)
    {
        v[y]++;
        ++u;
        g.push_back(y);
    }
    else if(x==2)
    {
        u-=v[y];
        v[y]=0;
        l[y]=g.size()-1;
    }
    else
    {
        for(int i=T;i<y;i++)
        {
            if(v[g[i]] && l[g[i]]<i)
            v[g[i]]--, u--;
        }

        if(y>T)
            T=y;
    }
    cout<<u<<'\n';
}
    return 0;
}
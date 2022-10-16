#include <bits/stdc++.h>
#define DMAX 30005
#define pb push_back
using namespace std;
int n, m, use[DMAX];
vector <int> v[DMAX];
vector <int> sol;

void dfs(int k)
{
    use[k]=1;
    for(int i=0;i<v[k].size();++i)
    {
        if(!use[v[k][i]])
            dfs(v[k][i]);
    }

    sol.pb(k);
}

int main()
{
    cin>>n>>m;
int a, b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[b].pb(a);
    }

    for(int i=1;i<=n;i++)
    if(!use[i])
    dfs(i);
    for(int i=sol.size()-1;i>=0;--i)
    {
        cout<<sol[i]<<' ';
    }
    return 0;
}
#define DMAX 100005
#include <bits/stdc++.h>

using namespace std;

int n, m, nrc, a, b, ans;
int use[DMAX];
vector <int> v[DMAX];
vector <vector<int> >c;

void dfs(int nod)
{
    use[nod]=1;

    c[nrc].push_back(nod);

    for(int i=0;i<v[nod].size();i++)
    {
        if(!use[v[nod][i]])
            dfs(v[nod][i]);
    }

}

int main()
{

    cin >> n >> m;

    for(int i=1;i<=m;i++)
    {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);

    }

    for(int i=1;i<=n;i++)
    {


        if(!use[i])
        {
            vector<int> e;
            c.push_back(e);
            dfs(i);
            nrc++;
        }
    }

    for(int i=0;i<c.size();i++)
    {
        int Count=0;

        for(int j=0;j<c[i].size();j++)
            Count+=v[c[i][j]].size();
        Count/=2;
        if(Count+1==c[i].size())
            ans+=1;
    }

    cout<<ans<<'\n';

    return 0;

}
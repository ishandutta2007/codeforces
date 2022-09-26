#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

vector<int> g[100500];
map<pair<int, int>, int> mp;
int used[100500];
int n;
vector<int> answ;
set<int> ans;
set<int> cur;
bool f;

int dfs(int v)
{
    cur.insert(v);

    used[v]=1;

    if (f)
        return -1;

    int r=-1;
    for (int i:g[v])
        if (used[i]==1)
        {
            if (r==-1)
                r=mp[{v, i}];
            else
                if (r!=mp[{v, i}])
                {
                    f=true;
                    return -1;
                }
        }

    if (r==1)
    {
        ans.insert(v);
        for (int i:g[v])
            mp[{v, i}]^=1, mp[{i, v}]^=1;
    }

    for (int i:g[v])
        if (used[i]==0)
            dfs(i);
}

int gr()
{
    f=false;
    memset(used, 0, sizeof(used));
    answ.clear();
    for (int i=1; i<=n; i++)
        if (used[i]==0)
    {
        cur.clear();
        ans.clear();

        dfs(i);
        if (f)
            return -1;

        if (2*ans.size()<cur.size())
            for (int j:ans)
                answ.pb(j);
        else
            for (int j:cur)
                if (ans.find(j)==ans.end())
                    answ.pb(j);
    }
}

/*
6 5
1 2 B
1 3 R
1 4 B
4 5 R
4 6 B

6 5
1 2 R
1 3 B
1 4 R
4 5 B
4 6 R

6 3
1 2 R
3 4 R
5 6 B
*/
main()
{
    int m;
    cin>>n>>m;
    map<pair<int,int>,int > mp2;
    for (int i=1, x,y; i<=m; i++)
    {
        string s;
        cin>>x>>y>>s;
        g[x].pb(y);
        g[y].pb(x);
        mp[{x, y}]=mp[{y, x}]=(s=="R");
        mp2[{x, y}]=mp2[{y, x}]=(s=="B");
    }

    if (gr()!=-1)
    {
        vector<int> prob=answ;
        mp=mp2;
        if (gr()==-1)
        {
            answ=prob;
        }
        else
        if (prob.size()<answ.size())
        {
            answ=prob;
        }

            cout<<answ.size()<<"\n";
            for (int i:answ)
                cout<<i<<" ";
    }
    else
    {
        mp=mp2;
        if (gr()==-1)
            cout<<-1<<"\n";
        else
        {
            cout<<answ.size()<<"\n";
            for (int i:answ)
                cout<<i<<" ";
        }
    }
    return 0;
}
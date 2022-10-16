#include <iostream>
#include <vector>

#define pb push_back
#define DMAX 102
using namespace std;

vector <int> v[DMAX][DMAX];

int a, b, c, n, m, maxc, ok, use[DMAX];

void dfs(int k, int start, int stop)
{
    if(start == stop)
        {ok = 1;
        return;
        }
    use[start]=1;
    for(int i=0; i<v[k][start].size(); i++)
    {
        int g=v[k][start][i];

        if(!use[g])
        {
            use[g]=1;
            dfs(k, g, stop);
        }
    }
    return ;
}

void reset_use()
{
    for(int i=0;i<=n;i++)
        use[i]=0;
}

int main()
{
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        cin>>a>>b>>c;
        if(c>maxc)
            maxc=c;
        v[c][b].pb(a);
        v[c][a].pb(b);
    }

    cin>>m;

    for(int i=1; i<=m; i++)
    {
        cin>>a>>b;
        int ans=0;

        for(int i=1; i<=maxc; i++)
            {
                ok=0;
                reset_use();
                dfs(i, a, b);
                ans+=ok;
            }
        cout<<ans<<'\n';
    }

    return 0;
}
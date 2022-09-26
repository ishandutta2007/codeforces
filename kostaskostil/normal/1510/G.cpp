#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 101;

typedef long double ld;
typedef long long ll;
//#define int ll

vector<int> g[nmax];

int ans[nmax][nmax];
int answ[nmax][nmax];
vector<int> path[nmax][nmax];
vector<int> pathw[nmax][nmax];
pair<int, int> pr[nmax][nmax];
pair<pair<int, int>, int> prw[nmax][nmax];

void dfs(int v, int p = -1)
{
    vector<int> low;
    for (int j : g[v])
        if (j != p)
        {
            low.pb(j);
            dfs(j, v);
        }
    int c = low.size();
    vector<int> cur(nmax, 1e9);
    vector<int> curw(nmax, 1e9);
    for (int i=0; i<=c; i++)
        for (int j=0; j<nmax; j++)
            pr[i][j] = {-1, -1}, prw[i][j] = {{-1, -1}, -1};
    cur[1] = 0;
    curw[1] = 0;

    for (int i = 0; i < c; i++)
    {
        auto curx = cur;
        auto curxw = curw;
        for (int j=0; j<nmax; j++)
            pr[i+1][j] = pr[i][j], prw[i+1][j] = prw[i][j];

        for (int j=1; j<nmax; j++)
            for (int k=1; j+k<nmax; k++)
            {
                if (curx[j+k] > cur[j] + ans[ low[i] ][ k ] + 2)
                {
                    curx[j+k] = cur[j] + ans[ low[i] ][ k ] + 2;
                    pr[i+1][j+k] = { i, j };
                }

                if (curxw[j+k] > curw[j] + ans[ low[i] ][ k ] + 2)
                {
                    curxw[j+k] = curw[j] + ans[ low[i] ][ k ] + 2;
                    prw[i+1][j+k] = { {i, j}, 0 };
                }
                if (curxw[j+k] > cur[j] + answ[ low[i] ][ k ] + 1)
                {
                    curxw[j+k] = cur[j] + answ[ low[i] ][ k ] + 1;
                    prw[i+1][j+k] = { {i, j}, 1 };
                }
            }
        cur = curx;
        curw = curxw;

//        if (v == 1)
//        {
//            for (int i : cur)
//                cout<<i<<" ";
//            cout<<"\n";
//            for (int i: curw)
//                cout<<i<<" ";
//            cout<<"\n";
//        }
    }

    for (int i=1; i<nmax; i++)
    {
        ans[v][i] = cur[i];


        path[v][i] = {v};
        int curc = c;
        int curj = i;

        while (true)
        {
            auto pa = pr[curc][curj];

            int ci = pa.fi;
            int cj = pa.se;
            if (ci == -1)
                break;

            for (int j : path[ low[ci] ][ curj - cj ])
                path[v][i].pb(j);
            path[v][i].pb(v);
            curc = ci;
            curj = cj;
        }

        answ[v][i] = curw[i];

        pathw[v][i] = {v};
        curc = c;
        curj = i;
        int lastOfUs = -1;
        int lastOfK = -1;
        while (true)
        {
            int ci, cj, f;
            f=0;
            if (lastOfUs != -1)
            {
                auto pa = pr[curc][curj];
                ci = pa.fi;
                cj = pa.se;
            }
            else
            {
                auto pa = prw[curc][curj];
                ci = pa.fi.fi;
                cj = pa.fi.se;
                f=pa.se;
            }

            if (ci == -1)
                break;

            if (f == 0)
            {
                for (int j : path[ low[ci] ][ curj - cj ])
                    pathw[v][i].pb(j);
                pathw[v][i].pb(v);
            }
            else
            {
                lastOfUs = ci;
                lastOfK = curj - cj;
            }

            curc = ci;
            curj = cj;
        }
        if (lastOfUs != -1)
        {
            for (int j : pathw[ low[ lastOfUs ] ][ lastOfK ] )
                pathw[v][i].pb(j);
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int ___;
    cin>>___;
    while (___--)
    {
        int n, k;
        cin>>n>>k;
        for (int i=0; i<nmax; i++)
            g[i].clear();
        for (int i=0; i<nmax; i++)
            for (int j=0; j<nmax; j++)
                ans[i][j] = 1e9, path[i][j].clear();

        for (int i = 2; i <= n; i++)
        {
            int x;
            cin>>x;
            g[x].pb(i);
            g[i].pb(x);
        }

        dfs(1);
//        cout<<answ[1][k]<<"\n";
        cout<<pathw[1][k].size()-1<<"\n";
        for (int i : pathw[1][k])
            cout<<i<<" ";
        cout<<"\n";
    }
}
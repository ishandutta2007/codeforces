#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 650;

int n;
int w[nmax][nmax];
int d[nmax][nmax];
int l[nmax][nmax];
int mx[nmax][nmax];

bool check(int u, int i, int c)
{
    if (mx[u][i] >= c)
        return true;
    return false;
}

void precalc(int u, int i)
{
    mx[u][i]=-1e18;
    for (int v=1; v<=n; v++)
        if (u!=v)
            mx[u][i]=max(mx[u][i], l[u][v]-d[i][v]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            w[i][j]=1e18;
    for (int i=1; i<=n; i++)
        w[i][i]=0;

    for (int i=1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y>>w[x][y];
        w[y][x]=w[x][y];
    }

    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y>>l[x][y];
        l[y][x]=l[x][y];
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            d[i][j]=w[i][j];
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            precalc(i, j);

//    for (int i=1; i<=n; i++, cout<<"\n")
//        for (int j=1; j<=n; j++)
//            cout<<setw(3)<<d[i][j]<<" ";

    int ans=0;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            for (int u=1; u<=n; u++)
            {
                if (check(u, i, d[u][j] + w[i][j])
                or  check(u, j, d[u][i] + w[i][j]))
                {
                    ans++;
                    break;
                }
            }

    cout<<ans<<"\n";
}
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 1e5+100;

typedef long double ld;
typedef long long ll;
//#define int ll
#define double ld

//vector<int> g[nmax];
//
//int ans[nmax][nmax];
//vector<int> path[nmax][nmax];
//
//void dfs(int i, int p = -1)
//{
//    vector<int> low;
//    for (int j : g[i])
//        if (j != p)
//        {
//            low.pb(j);
//            dfs(j, i);
//        }
//    int c = low.size();
//    vector<int> cur(nmax, 1e9);
//
//    for (int i = 0; i < c; i++)
//    {
//
//    }
//}

int a[nmax];
pair<int, int> pr[nmax][10];
double dp[nmax][10];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    bool adin=false;
    cin>>n>>d;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==1)
            adin=true;
    }
    for (int j=0; j<nmax; j++)
        for (int i=0; i<10; i++)
        {
            dp[j][i] = -1e9;
            pr[j][i] = {-1e9, -1e9};
        }
    dp[0][1] = 0;

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<10; j++)
            dp[i][j] = dp[i-1][j], pr[i][j] = pr[i-1][j];
        for (int j=0; j<10; j++)
        {
            int l = (j*a[i])%10;
            if (dp[i][l] < dp[i-1][j] + log(a[i]))
                dp[i][l] = dp[i-1][j] + log(a[i]), pr[i][l] = {i-1, j};
        }
    }

    vector<int> ans;
    int c = n;
    if (dp[n][d] < -1e-3)
        cout<<"-1\n", exit(0);
    if ((dp[n][d] < 1e-3) and (d==1))
    {
        if (adin)
            cout<<1<<"\n"<<1<<"\n";
        else
            cout<<"-1\n";
        exit(0);
    }

    while (true)
    {
        auto pa = pr[c][d];
        c=pa.fi;
        d=pa.se;

        if (d<0)
            break;
        ans.pb(c+1);
    }

    cout<<ans.size()<<"\n";
    for (int i : ans)
        cout<<a[i]<<" ";
    cout<<"\n";

}
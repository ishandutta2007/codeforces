#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

int n,m;
int a[550][550];
int b[550][550];

bool ch()
{
    for (int i=1; i<=n; i++)
    {
        int c=0;
        for (int j=1; j<=m; j++)
            c+=a[i][j];
        if (c%2==1)
            return false;
    }
    for (int i=1; i<=m; i++)
    {
        int c=0;
        for (int j=1; j<=n; j++)
            c+=a[j][i];
        if (c%2==1)
            return false;
    }
    return true;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>b[i][j], a[i][j]^=b[i][j];
    if (ch())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
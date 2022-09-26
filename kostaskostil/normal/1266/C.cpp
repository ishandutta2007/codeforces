#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    if ((n==1) and (m==1))
        cout<<0<<"\n";
    else if (m==1)
    {
        for (int i=1; i<=n; i++)
            cout<<i+1<<"\n";
    }
    else
    {
        for (int i=1; i<=n; i++, cout<<"\n")
        for (int j=1; j<=m; j++)
        {
            cout<<i*(n+j)<<" ";
        }
    }
}
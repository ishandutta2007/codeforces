#include <bits/stdc++.h>
#define int long long
using namespace std;



main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int,int> r;
    int n,m,a,b;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        r[a]=max(r[a],b);
    }
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        cin>>a>>b;
        r[a]=max(r[a],b);
    }
    int ans=0;
    for (map<int,int>::iterator it=r.begin(); it!=r.end(); it++)
        ans+=(*it).second;
    cout<<ans<<"\n";
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

int n,m;
int a[300100];
int b[300100];

set<pair<int, pair<int, int> > > s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    for (int i=1; i<n; i++)
        b[i]=a[i+1]-a[i];
    sort(b+1, b+n);
    int e=0;
    int c=n;
    if ((b[1]!=0) or (n==1))
        s.insert({0, {c, e}});
    for (int i=1; i<n; i++)
    {
        e+=b[i];
        c--;
        if ((i==n-1) or (b[i+1]!=b[i]))
            s.insert({b[i], {c, e}});
        //cout<<b[i]<<" "<<c<<" "<<e<<"\n";
    }
    int m;
    cin>>m;
    int l;
    int r;
    for (int i=1; i<=m; i++)
    {
        cin>>l>>r;
        r=(r-l+1);
        set<pair<int, pair<int, int> > >::iterator it=prev(s.upper_bound({r, {1e18+1, 1e18+1}}));
        cout<<(*it).se.fi*r+(*it).se.se<<"\n";

    }
    return 0;
}
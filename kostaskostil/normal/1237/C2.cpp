#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define int long long

#define fi first
#define se second
#define pb push_back

using namespace std;

set<pair<pair<int, int>, pair<int, int> > > p;

void mover()
{
    int t1=(*p.begin()).se.se;
    int x, y, z;
    x=(*p.begin()).fi.fi;
    y=(*p.begin()).fi.se;
    z=(*p.begin()).se.fi;

    p.erase(p.begin());

    int x0, y0, z0;
    x0=(*p.begin()).fi.fi;

    set<pair<pair<int, int>, pair<int, int> > >::iterator it=p.lower_bound({{x0, y}, {-1e9, 0}});
    if (it==p.end())
        it--;
    if ((*it).fi.fi!=x0)
        it--;

    y0=(*it).fi.se;
    it=p.lower_bound({{x0, y0}, {z, 0}});
    if (it==p.end())
        it--;
    if ( ((*it).fi.fi!=x0) or ((*it).fi.se!=y0) )
        it--;

    int ans=0;
    cout<<t1<<" "<<(*it).se.se<<"\n";
    p.erase(it);
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        p.insert({{x, y}, {z, i}});
    }

    for (int i=1; 2*i<=n; i++)
        mover();

    return 0;
}
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=500500;
int n;
vector< pair<pair<int, int>, int> > v1, v2;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x, y;
        cin>>x>>y;
        if (x<y)
        v1.pb({{-x, y}, i});
        else
        v2.pb({{y, x}, i});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1.size()<v2.size())
    {
        cout<<v2.size()<<"\n";
        for (auto pa:v2)
            cout<<pa.se<<" ";
        cout<<"\n";
    }
    else
    {
        cout<<v1.size()<<"\n";
        for (auto pa:v1)
            cout<<pa.se<<" ";
        cout<<"\n";
    }
}
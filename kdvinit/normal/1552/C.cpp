/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, k;
    cin>>n>>k;

    vector< array<int, 2> > xy;
    int freq[(2*n)+1]={0};

    for(int i=1; i<=k; i++)
    {
        int x, y; cin>>x>>y;
        int x2 = min(x, y);
        int y2 = max(x, y);
        xy.push_back({x2, y2});
        freq[x]=1;
        freq[y]=1;
    }

    vector<int> left;
    for(int i=1; i<=(2*n); i++)
    {
        if(freq[i]==0) left.push_back(i);
    }

    int m = left.size();
    int m2 = m/2;

    for(int i=0; i<m2; i++)
    {
        int x = left[i];
        int y = left[i+m2];
        xy.push_back({x, y});
    }
    sort(xy.begin(), xy.end());

    m = xy.size();

    int ans=0;
    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            int x1 = xy[i][0];
            int y1 = xy[i][1];
            int x2 = xy[j][0];
            int y2 = xy[j][1];
            if(x2<y1 && y1<y2) ans++;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
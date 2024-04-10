/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int ans[n+1];

    vector < array<int, 3> > time;
    for(int i=1; i<=n; i++)
    {
        int l, r;
        cin>>l>>r;
        time.push_back( {l, 0, i} );
        time.push_back( {r, 1, i} );
    }

    sort(time.begin(), time.end());

    int k = time.size();

    int ind = 0;
    set<int> seg;

    for(int i=0; i<k; i++)
    {
        if(seg.size()==0 && ind<2)
        {
            ind++;
        }

        auto x = time[i];
        if(x[1]==0)
        {
            seg.insert(x[2]);
            ans[x[2]]=ind;
        }
        else
        {
            seg.erase(x[2]);
        }
    }

    if(ind==1)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
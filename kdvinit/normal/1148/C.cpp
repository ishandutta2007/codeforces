/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;
    int m = n/2;

    int a[n+1];
    int pos[n+1];

    for(int i=1; i<=n; i++) { cin>>a[i]; pos[a[i]]=i; }

    vector<pair<int, int>> swps;

    for(int i=1; i<=n; i++)
    {
        if(a[i]==i) continue;
        int j = pos[i];

        a[j]=a[i];
        pos[a[j]]=j;

        a[i]=i;
        pos[a[i]]=i;

        int dif = j-i;
        if(dif>=m)
        {
            swps.push_back({i, j});
            continue;
        }

        if(i>m)
        {
            swps.push_back({1, i});
            swps.push_back({1, j});
            swps.push_back({1, i});
            continue;
        }
        
        if(j<=m)
        {
            swps.push_back({i, n});
            swps.push_back({j, n});
            swps.push_back({i, n});
            continue;
        }

        swps.push_back({i, n});
        swps.push_back({1, j});
        swps.push_back({1, n});
        swps.push_back({i, n});
        swps.push_back({1, j});
    }

    cout<<swps.size()<<endl;

    for(auto x: swps)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
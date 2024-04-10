/*
K.D. Vinit  |,,|
Don't Stalk
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> Day[m+1];
    for(int i=1; i<=m; i++)
    {
        int k; cin>>k;
        for(int j=1; j<=k; j++)
        {
            int x; cin>>x;
            Day[i].push_back(x);
        }
    }

    int freq[n+1]={0};
    int ans[m+1];
    for(int i=1; i<=m; i++)
    {
        if(Day[i].size()!=1) continue;
        int x = Day[i][0];
        freq[x]++;
        ans[i]=x;
    }

    int mx = (m+1)/2;

    for(int i=1; i<=n; i++)
    {
        if(freq[i]>mx) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;

    for(int i=1; i<=m; i++)
    {
        if(Day[i].size()==1) continue;
        int x = Day[i][0];
        int y = Day[i][1];

        if(freq[x]<mx)
        {
            ans[i]=x;
            freq[x]++;
        }
        else
        {
            ans[i]=y;
            freq[y]++;
        }
    }

    for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int a[n+2],freq[201][n+1],ans=0;
    vector<int> pos[201];

    for(int j=1;j<=200;j++) freq[j][0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]].push_back(i);
        for(int j=1;j<=200;j++)
        {
            freq[j][i]=freq[j][i-1];
        }
        freq[a[i]][i]++;
        ans=max(ans,freq[a[i]][i]);
    }

    for(int i=1;i<=200;i++)
    {
        for(int j=1;j<=200;j++)
        {
            if(i==j) continue;
            if(freq[i][n]==0 || freq[j][n]==0) continue;

            int strt, nd;
            int m=pos[i].size();
            for(int cnt=1;(2*cnt)<=m; cnt++)
            {
                strt=pos[i][cnt-1];
                nd=pos[i][m-cnt];

                int tmp=(2*cnt)+(freq[j][nd-1]-freq[j][strt]);
                ans=max(ans,tmp);
            }
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
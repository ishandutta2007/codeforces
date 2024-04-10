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

    int u[n+1], s[n+1], tot=0;
    for(int i=1; i<=n; i++) cin>>u[i];
    for(int i=1; i<=n; i++) { cin>>s[i]; tot+=s[i]; }

    vector<int> skills[n+1];

    for(int i=1; i<=n; i++)
    {
        skills[u[i]].push_back(s[i]);
    }

    int ans[n+1];
    int xtra[n+2]={0};

    for(int i=1; i<=n; i++) ans[i]=tot;

    for(int i=1; i<=n; i++)
    {
        int m = skills[i].size();
        sort(skills[i].begin(), skills[i].end());

        int tmp=0;
        for(int j=0; j<m; j++)
        {
            tmp+=skills[i][j];
            int len = m-1-j;

            for(int k=1; k*k<=len; k++)
            {
                if(len%k!=0) continue;
                int f1 = k;
                int f2 = len/k;

                if(f1>j+1) ans[f1]-=tmp;
                if(f1!=f2 && f2>j+1) ans[f2]-=tmp;
            }
        }

        xtra[m+1]+=tmp;
    }

    for(int i=2; i<=n; i++) xtra[i]+=xtra[i-1];

    for(int i=1; i<=n; i++) ans[i]-=xtra[i];

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
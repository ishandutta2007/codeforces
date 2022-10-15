/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int cnt[n]={0}, tot=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char x; cin>>x;
            if(x=='1')
            {
                tot++;
                int dif = (i-j+n)%n;
                cnt[dif]++;
            }
        }
    }

    int ans=tot+n;

    for(int i=0; i<n; i++)
    {
        int x = cnt[i];
        int tmp = (tot-x) + (n-x);
        ans = min(ans, tmp);
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
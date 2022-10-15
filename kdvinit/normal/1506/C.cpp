/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string a, b;
    cin>>a>>b;

    int n = a.size();
    int m = b.size();

    int ans = n+m;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j+i<=n; j++)
        {
            for(int k=0; k+i<=m; k++)
            {
                if(a.substr(j,i)!=b.substr(k,i)) continue;
                ans=min(ans,n-i+m-i);
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
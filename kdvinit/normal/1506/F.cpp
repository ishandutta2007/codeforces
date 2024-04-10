/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int val(int r, int c)
{
    int ans = r-c;
    ans = (ans+1)/2;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    array<int, 2> rc[n+1];
    for(int i=1; i<=n; i++) cin>>rc[i][0];
    for(int i=1; i<=n; i++) cin>>rc[i][1];

    sort(rc+1, rc+n+1);
    rc[0][0]=1;
    rc[0][1]=1;

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int r = rc[i+1][0]-rc[i][0];
        int c = rc[i+1][1]-rc[i][1];

        int par = (rc[i][0] + rc[i][1])%2;
        if(par==1)
        {
            ans+=val(r, c);
        }
        else
        {
            if(r==c) ans+=r;
            else
            {
                r--;
                ans+=val(r, c);
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
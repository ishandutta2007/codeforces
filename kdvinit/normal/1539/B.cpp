/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, q;
    cin>>n>>q;

    int sum[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        sum[i] = sum[i-1] + (x-'a'+1);
    }

    while(q--)
    {
        int l, r;
        cin>>l>>r;
        int ans = sum[r]-sum[l-1];
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
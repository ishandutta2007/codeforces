/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    int ans=0;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;

        if(x=='0') a[i]=0;
        else a[i]=1;
    }

    if(a[1]==0) ans=1;

    int len=0;
    for(int i=2;i<=n;i++)
    {

        if(a[i]==0) len++;
        else
        {
            if(len<k) ans--;
            len=0;
        }

        if(len==k+1)
        {
            ans++;
            len=0;
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
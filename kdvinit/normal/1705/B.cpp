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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int sum=0;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(i==n || a[i]==0)
        {
            if(i==n) ans+=sum;
            else
            {
                if(sum!=0) ans++;
            }
        }
        else sum+=a[i];
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
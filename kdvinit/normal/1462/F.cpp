/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    pair<int,int> a[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        a[i]={l,r};
        b[i]=r;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    int j=1,mx=0,k=1;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        while(j<=n && a[j].first<=b[i])
        {
            mx=max(mx,a[j].second);
            j++;
        }

        while(k<=n && a[k].first<=mx) k++;

        int temp=i-1+n+1-k;
        ans=min(ans,temp);

    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
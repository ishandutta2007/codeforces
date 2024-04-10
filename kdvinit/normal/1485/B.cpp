/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,q,k;
    cin>>n>>q>>k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int val[n+1]={0};
    for(int i=2;i<n;i++)
    {
        int tmp=a[i+1]-a[i-1]-2;
        val[i]=val[i-1]+tmp;
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        if(r==l) { cout<<k-1<<endl; continue; }

        int ans=(k-a[r-1]-1);
        ans+=(a[l+1]-2);

        if(r==l+1)
        {
            cout<<ans<<endl;
            continue;
        }

        ans+=val[r-1];
        ans-=val[l];
        cout<<ans<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
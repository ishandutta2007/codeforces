/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    for(int i=2; i<=n; i++) a[i]+=a[i-1];

    while(q--)
    {
        int x; cin>>x;

        int l=0, r=n+1;
        while(l+1!=r)
        {
            int mid = (l+r)/2;
            if(a[mid]>=x) r=mid;
            else l=mid;
        }

        if(r==n+1) r=-1;
        cout<<r<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
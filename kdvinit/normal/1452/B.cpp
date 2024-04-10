/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int sum, mx, n;

bool chk(int k)
{
    if(k*(n-1)<sum) return false;
    if(k<mx) return false;

    return true;
}

int Get_K()
{
    int l=-1, r=1e10;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(chk(mid)) r=mid;
        else l=mid;
    }

    return r;
}

void solve()
{
    cin>>n;

    int a[n+1];
    sum = 0;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    sort(a+1, a+n+1);
    mx = a[n];

    int ans = (Get_K()*(n-1))-sum;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int poww(int a, int b)
{
    int ans=1;
    while(b>0) { b--; ans*=a; }
    return ans;
}

void solve()
{
    int n, k;
    cin>>n>>k;
    k++;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans=0;
    for(int i=1; i<n; i++)
    {
        int cv = poww(10, a[i]);
        int dv = poww(10, a[i+1] - a[i]);
        dv--;

        int cnt=min(k, dv);
        k-=cnt;

        ans+=(cnt*cv);
    }

    int cv = poww(10, a[n]);
    ans += (cv*k);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
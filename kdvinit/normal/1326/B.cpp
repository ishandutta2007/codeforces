/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int b[n+1];
    for(int i=1;i<=n;i++) cin>>b[i];

    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int x=mx+b[i];
        cout<<x<<" ";
        mx=max(mx,x);
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int x, n;
    cin>>x>>n;

    int k = (n/4);
    k*=4;

    for(int i=k+1; i<=n; i++)
    {
        if(x%2==0) x-=i;
        else x+=i;
    }

    cout<<x<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
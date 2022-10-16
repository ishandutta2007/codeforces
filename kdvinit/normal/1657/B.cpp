/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, b, x, y;
    cin>>n>>b>>x>>y;

    int cur=0, sum=0;
    for(int i=1; i<=n; i++)
    {
        if(cur+x>b) cur-=y;
        else cur+=x;
        sum+=cur;
    }

    cout<<sum<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
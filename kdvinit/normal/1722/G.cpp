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

    int cur=0;

    int a[n+1];
    for(int i=1; i<=n-2; i++)
    {
        a[i]=i;
        cur^=i;
    }

    if(cur==0)
    {
        a[n-2]=n-1;
        cur^=(n-2);
        cur^=(n-1);
    }

    int mx = 1<<30;
    a[n-1]=mx;
    cur^=mx;

    a[n]=cur;

    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
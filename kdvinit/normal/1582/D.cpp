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

    if(n%2==0)
    {
        int m = n/2;
        for(int i=1; i<=n; i++)
        {
            int x = a[n+1-i];
            if(i<=m) x*=-1;
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else
    {
        int m = (n-3)/2;
        for(int i=1; i<=n-3; i++)
        {
            int x = a[n-2-i];
            if(i<=m) x*=-1;
            cout<<x<<" ";
        }
        
        int x = a[n-2];
        int y = a[n-1];
        int z = a[n];
        
        if((x*y)>0)
        {
            cout<<z<<" "<<z<<" "<<-(x+y)<<endl;
        }
        else if((y*z)>0)
        {
            cout<<-(y+z)<<" "<<x<<" "<<x<<endl;
        }
        else
        {
            cout<<y<<" "<<-(x+z)<<" "<<y<<endl;
        }
        
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
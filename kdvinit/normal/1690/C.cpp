#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve()
{
    int n; cin>>n;
    
    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    
    int lst=0;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        int y = x - max(lst, a[i]);
        cout<<y<<" ";
        lst=x;
    }
    cout<<endl;
}

int32_t main() 
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve()
{
    int n, k; 
    cin>>n>>k;
    
    int a[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='B') a[i]=1;
        a[i]+=a[i-1];
    }
    
    int ans=k;
    for(int i=k; i<=n; i++)
    {
        int tmp = k - (a[i]-a[i-k]);
        ans = min(ans, tmp);
    }
    
    cout<<ans<<endl;
}

int32_t main() 
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
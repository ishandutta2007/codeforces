#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    
    int a[n+2];
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int mx=a[1];
    for(int i=2;i<=n;i++) mx=max(mx,a[i]);
    
    a[0]=mx; a[n+1]=mx;
    for(int i=1;i<=n;i++)
    {
        if( (a[i]==mx) && ( a[i-1]!=mx || a[i+1]!=mx ) ) 
        {
             cout<<i<<endl; 
             return; 
        }
    }
    
    cout<<-1<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve()
{
    int n; cin>>n;
    
    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    
    set<int> st;
    int mx=0;
    
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(x==0) mx = max(mx, a[i]); 
        else st.insert(a[i]-x);
    }
    
    if(st.size()==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    
    if(st.size()==1)
    {
        int y = *st.begin();
        if(y>=mx) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    
    cout<<"NO"<<endl;
}

int32_t main() 
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
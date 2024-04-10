#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve()
{
    int n, k; 
    cin>>n>>k;
    
    multiset<int> st;
    int ans = 0;
    
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        ans += (x/k);
        x%=k;
        st.insert(x);
    }
    
    while(1)
    {
        if(st.size()<2) break;
        int x = *st.rbegin();
        st.erase(st.find(x));
        
        st.insert(k);
        int y = *st.lower_bound(k-x);
        st.erase(k);
        
        if(y==k) break;
        st.erase(st.find(y));
        ans++;
    }
    
    cout<<ans<<endl;
}

int32_t main() 
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
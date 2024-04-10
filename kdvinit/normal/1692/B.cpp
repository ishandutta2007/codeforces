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

    set<int> st;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        st.insert(x);
    }

    int m = st.size();

    if(m%2!=n%2) m--;
    cout<<m<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
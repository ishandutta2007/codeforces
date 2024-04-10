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

    set<int> st;
    for(int i=1; i<=n; i++) st.insert(i);

    int atl[n+1]={0};
    for(int i=n; i>=1; i--)
    {
        int mn = *st.begin();
        if(a[i]==mn) atl[i]=1;
        st.erase(a[i]);
    }

    deque<int> dq;

    for(int i=1; i<=n; i++)
    {
        if(atl[i]==1) dq.push_front(a[i]);
        else dq.push_back(a[i]);
    }

    for(int x: dq) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
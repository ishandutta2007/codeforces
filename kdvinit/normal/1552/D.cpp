/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    set<int> st;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        x = abs(x);
        a[i] = x;

        if(x!=0) st.insert(x);
    }

    int m = st.size();
    if(m<n) { cout<<"YES"<<endl; return; }

    map<int, int> mp;

    int mx = 1<<n;
    for(int i=0; i<mx; i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            int bm = 1<<j;
            if((i&bm)==0) continue;
            sum+=a[j+1];
        }
        //cout<<i<<" "<<sum<<endl;

        if(mp[sum]==1) { cout<<"YES"<<endl; return; }
        mp[sum]=1;
    }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
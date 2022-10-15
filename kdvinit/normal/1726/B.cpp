/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    if(n>m) { cout<<"No"<<endl; return; }

    if(n%2==1)
    {
        cout<<"Yes"<<endl;
        for(int i=1; i<n; i++) cout<<1<<" ";
        cout<<(m-(n-1))<<endl;
        return;
    }

    if(m%2==1) { cout<<"No"<<endl; return; }

    cout<<"Yes"<<endl;
    for(int i=1; i<=n-2; i++) cout<<1<<" ";

    m = (m-(n-2))/2;
    cout<<m<<" "<<m<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
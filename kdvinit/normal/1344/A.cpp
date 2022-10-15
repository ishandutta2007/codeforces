/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,x;
    cin>>n;

    vector<int> a;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        x+=i;
        x%=n;
        x+=n;
        x%=n;
        a.push_back(x);
    }
    sort(a.begin(),a.end());

    for(int i=1;i<n;i++)
    {
        if(a[i-1]==a[i]) { cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    if(n==k)
    {
        for(int i=1;i<=k;i++) cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        int r=n-k;
        r++;
        int m=k-r;
        //cout<<"Hello - "<<m<<" "<<r<<endl;
        for(int i=1;i<=m;i++) cout<<i<<" ";
        for(int i=k;i>m;i--) cout<<i<<" ";
        cout<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
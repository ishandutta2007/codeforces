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
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    if(a[1]<0) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<101<<endl;
        for(int i=0; i<=100; i++) cout<<i<<" ";
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
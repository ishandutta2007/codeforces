/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ya cout<<"YES"<<endl;
#define nah cout<<"NO"<<endl;

void solve()
{
    int n,k;
    cin>>n>>k;

    if(k<n)
    {
        int x=n/k;
        if(n%k!=0) x++;
        k*=x;
    }

    int ans=k/n;
    if(k%n!=0) ans++;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
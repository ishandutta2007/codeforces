/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int w,h,n;
    cin>>w>>h>>n;

    int ans1=1,ans2=1;

    while(w%2==0)
    {
        w/=2;
        ans1*=2;
    }
    while(h%2==0)
    {
        h/=2;
        ans2*=2;
    }

    ans1*=ans2;
    if(ans1>=n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, a, b;
    cin>>n>>a>>b;

    if((n-1)%b==0) { cout<<"Yes"<<endl; return; }

    if(a!=1)
    {
        int x=1;
        while(x<=n)
        {
            if((n-x)%b==0) { cout<<"Yes"<<endl; return; }
            x*=a;
        }
    }

    cout<<"No"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
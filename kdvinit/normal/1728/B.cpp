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

    if(n%2==1)
    {
        cout<<1<<" ";
        for(int i=2; i<=n-2; i++) cout<<n-2-i+2<<" ";
        cout<<n-1<<" "<<n<<endl;
        cout<<endl;
    }
    else
    {
        for(int i=1; i<=n-2; i++) cout<<n-2-i+1<<" ";
        cout<<n-1<<" "<<n<<endl;
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
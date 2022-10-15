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

    if(n==3)
    {
        cout<<-1<<endl;
        return;
    }

    cout<<n<<" "<<n-1<<" ";
    for(int i=3; i<=n; i++) cout<<i-2<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
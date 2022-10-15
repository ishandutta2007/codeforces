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

    int sum=-n;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        sum+=x;
    }

    if(sum%2==0) cout<<"maomao90"<<endl;
    else cout<<"errorgorn"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
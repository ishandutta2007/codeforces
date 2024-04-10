/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int s1=0, s2=0;

    for(int i=1; i<=3; i++)
    {
        char x; cin>>x;
        s1+=(x-'0');
    }

    for(int i=1; i<=3; i++)
    {
        char x; cin>>x;
        s2+=(x-'0');
    }

    if(s1==s2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
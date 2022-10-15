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

    if(n<=26)
    {
        for(int i=1; i<=n; i++)
        {
            char x = 'a'+i-1;
            cout<<x;
        }
        cout<<endl;
        return;
    }

    if(n%2==0)
    {
        int m = (n-1)/2;
        for(int i=1; i<=m; i++) cout<<"a";
        cout<<"b";
        for(int i=1; i<=(m+1); i++) cout<<"a";
        cout<<endl;
        return;
    }

    int m = n-1;

    int x = m/2;
    int y = m/2;

    if(x%2==0) { x++; y--; }

    x/=2;
    y/=2;

    for(int i=1; i<=x; i++) cout<<"c";
    for(int i=1; i<=y; i++) cout<<"a";
    cout<<"b";
    for(int i=1; i<=(y+1); i++) cout<<"a";
    for(int i=1; i<=(x+1); i++) cout<<"c";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
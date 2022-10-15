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

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'a';
    }

    for(int i=1; i+1<=n; i++)
    {
        if(a[i]==0 && a[i+1]==0) { cout<<2<<endl; return; }
    }

    for(int i=1; i+2<=n; i++)
    {
        if(a[i]==0 && a[i+2]==0) { cout<<3<<endl; return; }
    }

    for(int i=1; i+3<=n; i++)
    {
        if(a[i]==0 && a[i+3]==0 && a[i+1]!=a[i+2]) { cout<<4<<endl; return; }
    }

    for(int i=1; i+6<=n; i++)
    {
        if(a[i]==0 && a[i+3]==0 && a[i+6]==0 && a[i+1]==a[i+2] && a[i+4]==a[i+5] && a[i+1]!=a[i+4]) { cout<<7<<endl; return; }
    }

    cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
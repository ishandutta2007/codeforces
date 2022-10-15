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

    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    char lst='?';
    for(int i=1; i<=n; i++)
    {
        if(a[i]=='?')
        {
            if(lst=='?') continue;
            if(lst=='R') a[i]='B';
            else a[i]='R';
        }
        lst = a[i];
    }

    lst='R';
    for(int i=n; i>=1; i--)
    {
        if(a[i]=='?')
        {
            if(lst=='R') a[i]='B';
            else a[i]='R';
        }
        lst = a[i];
    }

    for(int i=1; i<=n; i++) cout<<a[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
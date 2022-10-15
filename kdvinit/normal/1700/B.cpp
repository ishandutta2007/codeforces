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
        a[i]=x-'0';
    }

    if(a[1]!=9)
    {
        for(int i=1; i<=n; i++) cout<<9-a[i];
        cout<<endl;
        return;
    }
    else
    {
        int b[n+1];
        int car=0;

        for(int i=n; i>0; i--)
        {
            b[i]=1-a[i]+car;
            if(b[i]<0) { b[i]+=10; car=-1; }
            else car=0;
        }

        for(int i=1; i<=n; i++) cout<<b[i];
        cout<<endl;
        return;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
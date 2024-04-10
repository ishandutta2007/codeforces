/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, r, b;
    cin>>n>>r>>b;

    int fl = r/(b+1);
    int ex = r%(b+1);
    int nm = b+1-ex;

    for(int i=1; i<=nm; i++)
    {
        for(int j=1; j<=fl; j++) cout<<"R";
        if(ex==0 && i==nm) continue;
        cout<<"B";
    }

    for(int i=1; i<=ex; i++)
    {
        for(int j=1; j<=fl+1; j++) cout<<"R";
        if(i!=ex) cout<<"B";
    }

    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
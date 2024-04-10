/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    if(m<n) { cout<<0<<endl; return; }

    int dif = m-n, x=0;
    for(int i=1; i<=31; i++)
    {
        int y = 1<<(i-1);
        if( (n&y)!=0 ) continue;
        x+=y;
    }

    //cout<<dif<<endl;
    for(int i=31; i>=1; i--)
    {
        int y = 1<<(i-1);
        //cout<<i<<" "<<y<<endl;
        if( (n&y)!=0 ) continue;
        int z = x-y;
        //cout<<i<<" "<<z<<endl;
        if(z<=dif) continue;
        x=z;
    }
    cout<<x<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
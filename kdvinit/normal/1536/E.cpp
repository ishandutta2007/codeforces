/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

void solve()
{
    int n, m;
    cin>>n>>m;

    int cnt0=0, cnt1=1;
    for(int i=1; i<=(n*m); i++)
    {
        char x; cin>>x;
        if(x=='0') cnt0++;
        else
        {
            cnt1*=2;
            cnt1%=mod;
        }
    }

    if(cnt0==0) cnt1--;
    cnt1+=mod; cnt1%=mod;

    cout<<cnt1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
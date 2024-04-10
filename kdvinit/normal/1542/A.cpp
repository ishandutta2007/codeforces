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

    int cnt1=0, cnt2=0, x;
    for(int i=1; i<=(2*n); i++)
    {
        cin>>x;
        if(x%2==1) cnt1++;
        else cnt2++;
    }

    if(cnt1==cnt2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
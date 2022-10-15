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


    int lst=0;
    for(int i=1;i<=n;i++)
    {
        char y; cin>>y;
        int x=y-48;
        int z=1;
        if(z+x==lst) z--;
        cout<<z;
        lst=x+z;
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
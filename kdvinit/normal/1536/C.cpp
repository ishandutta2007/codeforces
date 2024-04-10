/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int GCD(int x, int y)
{
   if(y==0) return x;
   else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    map<pair<int, int>, int> mp;

    int D=0, K=0;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='D') D++;
        else K++;

        int y = D;
        int z = K;
        int w = GCD(y, z);
        y/=w;
        z/=w;
        cout<<++mp[{y, z}]<<" ";
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
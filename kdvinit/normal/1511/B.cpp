/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int Num_Digits(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans++;
        x/=10;
    }
    return ans;
}

void solve()
{
    int a, b, c;
    cin>>a>>b>>c;

    int z = 1;
    while(Num_Digits(z)!=c) z*=3;

    int x = z;
    while(Num_Digits(x)!=a) x*=5;

    int y = z;
    while(Num_Digits(y)!=b) y*=7;

    cout<<x<<" "<<y<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
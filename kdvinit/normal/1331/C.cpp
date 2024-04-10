/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x;
    cin>>x;

    int a[7];
    for(int i=1; i<=6; i++)
    {
        a[7-i]=x%2;
        x/=2;
    }
    int b[7]={0,1,6,4,3,5,2};

    int y=0;
    for(int i=1; i<=6; i++)
    {
        y*=2;
        y+=a[b[i]];
    }
    cout<<y<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
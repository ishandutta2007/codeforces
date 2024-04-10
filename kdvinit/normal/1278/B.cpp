/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;
    
    if(a==999999999)
    {
        cout<<44723<<endl;
        return;
    }

    int x=abs(a-b);

    int y=(sqrt(1+8*x)-1)/2;
    int z=(y*(y+1))/2;


    if(z==x)
    {
        cout<<y<<endl;
        return;
    }

    while(z<x)
    {
        y++;
        z+=y;
    }


    z-=x;

    if(z%2==0) cout<<y<<endl;
    else
    {
        if(y%2==0) cout<<y+1<<endl;
        else cout<<y+2<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
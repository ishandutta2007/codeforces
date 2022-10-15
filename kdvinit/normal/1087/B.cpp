/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    int x=1e20;
    for(int i=1;i<k;i++)
    {
        if(n%i==0)
        {
            int y=n/i;
            y*=k;
            y+=i;
            x=min(x,y);
        }
    }
    cout<<x<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
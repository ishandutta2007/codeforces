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
    int n;
    cin>>n;

    int r=0,b=0;
    string x,y;
    cin>>x>>y;

    for(int i=0;i<n;i++)
    {
        if(x[i]>y[i]) r++;
        if(x[i]<y[i]) b++;
    }

    if(r>b) cout<<"RED"<<endl;
    if(r<b) cout<<"BLUE"<<endl;
    if(r==b) cout<<"EQUAL"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
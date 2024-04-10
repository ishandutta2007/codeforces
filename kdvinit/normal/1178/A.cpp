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

    int a[n+1];
    cin>>a[1];
    int suma=a[1],total=a[1];

    vector<int> pos;
    pos.push_back(1);
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        total+=a[i];
        if(a[1]>=2*a[i])
        {
            suma+=a[i];
            pos.push_back(i);
        }
    }

    if(2*suma<=total) { cout<<0<<endl; return; }

    cout<<pos.size()<<endl;

    for(int i=0;i<pos.size();i++) cout<<pos[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
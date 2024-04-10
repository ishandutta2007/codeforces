/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

bool Pyt(int a,int b,int c)     // Pythagorous
{
    if(a*a + b*b <= c*c) return true;
    else return false;
}

void solve()
{
    int d,k;
    cin>>d>>k;

    int z=0;
    while( Pyt(z+k,z+k,d) ) z+=k;

    if( Pyt(z,z+k,d) ) cout<<"Ashish"<<endl;
    else cout<<"Utkarsh"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
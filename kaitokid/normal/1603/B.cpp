#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    ll x,y;
    cin>>x>>y;
    if(y<x){cout<<x*y+y<<endl;continue;}

    x*=(y/x);

    cout<<(x+y)/2<<endl;

    }

    return 0;
}
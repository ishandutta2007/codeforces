#include <bits/stdc++.h>
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
        if(x==0 && y==0){cout<<0<<endl;continue;}
        ll p=x*x + y*y;
        ll r=sqrt(p);
        if(r*r==p){cout<<1<<endl;continue;}
        cout<<2<<endl;

    }
}
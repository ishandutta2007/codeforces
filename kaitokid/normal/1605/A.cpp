#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll d=abs(a+c-2*b);
        if(d%3==0)cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
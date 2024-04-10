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

    ll n;
    cin>>n;
    ll mx=0,sum=0,g=1;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        while(x%2==0){g*=2;x/=2;}
        mx=max(mx,x);
        sum+=x;
    }

    sum-=mx;
    mx*=g;
    sum+=mx;

    cout<<sum<<endl;
    }
    return 0;
}
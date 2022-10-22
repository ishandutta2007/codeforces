#include <bits/stdc++.h>
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
        ll n,sum=0,x;
        cin>>n;
        for(int i=0;i<n;i++){cin>>x;sum+=x;}
        ll d=sum%n;
        d*=(n-d);
        cout<<d<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[109];
int main()
{
int t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    if(n%2){cout<<"NO\n";continue;}
    n/=2;
    ll u=sqrt(n);
    if((u*u)==n){cout<<"YES\n";continue;}
    if(n%2){cout<<"NO\n";continue;}
    n/=2;
     u=sqrt(n);
    if((u*u)==n){cout<<"YES\n";continue;}
    cout<<"NO\n";
}


    return 0;
}
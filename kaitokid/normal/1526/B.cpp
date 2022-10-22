#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
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
     ll r=n/111;
     ll u=(n%111)%11;
     ll p=(11-u)%11;
     if(p>r)cout<<"NO\n";
     else cout<<"YES\n";
    }

}
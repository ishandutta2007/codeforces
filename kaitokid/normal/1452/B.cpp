#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 int t;

 cin>>t;
 while(t--)
 {
     ll n,x,mx=0,sum=0;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>x;
         sum+=x;
         mx=max(x,mx);
     }
     ll p=mx*(n-1);
    ll v=sum;
    if(v%(n-1))v+=n-1-v%(n-1);
    p=max(p,v);
     cout<<p-sum<<endl;
 }
    return 0;
}
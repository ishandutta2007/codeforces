#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t;


    cin>>t;
    while(t--)
    {
   ll n;

 ll x,sum=0,z;
cin>>n>>x;
bool bl=false,bu=false;
for(int i=0;i<n;i++)
{
    cin>>z;
    if(z==x)bu=true;
    if(z!=x)bl=true;
    sum+=z;
}
if(!bl){cout<<0<<endl;continue;}

if(bu==true)
{
    cout<<1<<endl;
    continue;
}
if(sum%n==0&&(sum/n==x)){cout<<1<<endl;continue;}
cout<<2<<endl;


    }
    return 0;
}
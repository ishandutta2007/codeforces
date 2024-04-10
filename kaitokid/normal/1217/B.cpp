#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long long n,t,x,dd,mx,h,d;
int main()
{
    cin>>t;
    while(t--)
    {
cin>>n>>x;
dd=0,mx=0;
for(ll i=0;i<n;i++)
{
    cin>>d>>h;
    dd=max(dd,d-h);
    mx=max(mx,d);
}
if(mx>=x){cout<<1<<endl;continue;}
if(dd==0){ cout<<-1<<endl; continue;}
    x-=mx;
    cout<<1+((x+dd-1)/dd)<<endl;


    }
    return 0;
}
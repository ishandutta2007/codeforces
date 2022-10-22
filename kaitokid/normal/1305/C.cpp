#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[2009],m;
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
if(n>2000){cout<<0;return 0;}
ll ans=(1%m);
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
{
    ans*=((abs(a[i]-a[j]))%m);
    ans%=m;
}
cout<<ans;
    return 0;
}
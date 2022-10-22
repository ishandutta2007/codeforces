#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n,ans;
int main()
{
ios::sync_with_stdio(0);
ll d=0, x;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
ll r=min(d,x/2);
ans+=r;
d-=r;
x-=2*r;
ans+=(x/3);
x%=3;
d+=x;

}
cout<<ans;

return 0;
}
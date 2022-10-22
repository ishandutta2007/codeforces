#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,mx,sum,x;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
ll m=n;
while(m--){cin>>x;sum+=x;mx=max(x,mx);}
cout<<fixed<<setprecision(0)<<max(mx+0.0,ceil((sum+0.0)/(n-1.0)));

return 0;}
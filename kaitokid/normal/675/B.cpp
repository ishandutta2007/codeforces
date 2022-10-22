#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int main()
{ios::sync_with_stdio(0);
ll n,a,b,c,d;
cin>>n>>a>>b>>c>>d;
ll x=1,y=n;
x=max(x,c-b+1);
x=max(x,d-a+1);
x=max(x,c+d-a-b+1);
y=min(y,c-b+n);
y=min(y,d-a+n);
y=min(y,c+d-a-b+n);
ll p=0;
cout<<n*max(p,y-x+1);
return 0;}
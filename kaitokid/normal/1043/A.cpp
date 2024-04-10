#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{ios::sync_with_stdio(0);
int n,x,mx=0,s=0;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x;
    mx=max(mx,x);
    s+=x;
}
int u=(2*s+1+n-1)/n;
u=max(u,mx);
cout<<u;
    return 0;
}
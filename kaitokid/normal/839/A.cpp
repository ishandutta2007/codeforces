#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,k,x,h,ans;
int main()
{
    ios::sync_with_stdio(0);
cin>>n>>k;
for(int i=0;i<n;i++)
{
    cin>>x;
    h+=x;
    int u=min(8,h);
    k-=u;
    h-=u;
    if(k<=0){cout<<i+1;return 0;}
}
cout<<-1;
    return 0;
}
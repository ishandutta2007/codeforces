#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[109];
int main()
{
    ios::sync_with_stdio(0);
   cin>>n;
   for(int i=0;i<n;i++)cin>>a[i];
   sort(a,a+n);
for(int i=0;i<n;i+=2)cout<<a[i]<<" ";

int u=n-1;
if(u%2==0)u--;
for(int i=u;i>0;i-=2)cout<<a[i]<<" ";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,m;
ll a[505];
int main()
{
ios::sync_with_stdio(0);
scanf("%d",&n);
for(int i=0;i<n;i++)scanf("%lld",&a[i]);
ll ans=0;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int q=0;q<n;q++)
ans=max(ans,a[i]|a[j]|a[q]);
printf("%lld",ans);
    return 0;
}
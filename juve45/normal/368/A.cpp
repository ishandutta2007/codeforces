#include <bits/stdc++.h>

using namespace std;
int n, d, ans, a[123], m;


int main()
{
cin>>n>>d;

for(int i=1;i<=n;i++)
    cin>>a[i];
cin>>m;

sort(a+1, a+n+1);

for(int i=1;i<=m && i<=n;i++)
    ans+=a[i];

for(int i=n+1;i<=m;i++)
    ans-=d;

cout<<ans;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
int t,n,a[100];
cin>>t;
while(t--)
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int ans=10000;
    for(int i=1;i<n;i++)ans=min(ans,a[i]-a[i-1]);
cout<<ans<<endl;
}

    return 0;
}
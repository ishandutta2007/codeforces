#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int n,a[55],t;
cin>>t;
while(t--)
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int u=n-1;

    bool ans=true;
    for(int i=1;i<n;i++)if(a[i]-a[i-1]>1)ans=false;
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}
    return 0;
}
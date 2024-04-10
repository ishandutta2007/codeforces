#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[38],b[38],ans;
int main()
{ios::sync_with_stdio(0);
ll t,n,k;
cin>>t;
while(t--)
{
    cin>>n>>k;
    ans=0;
    for(int i=0;i<n;i++){cin>>a[i];ans+=a[i];}
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<k;i++)ans+=max(0LL,b[n-1-i]-a[i]);
    cout<<ans<<endl;
}
    return 0;
}
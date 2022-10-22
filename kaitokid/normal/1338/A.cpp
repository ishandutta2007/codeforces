#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,a[100009],mx[100009];
int main()
{ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
    ll ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
cin>>a[i];
mx[0]=a[0];
    for(int i=1;i<n;i++)
    {mx[i]=max(mx[i-1],a[i]);
    ll u=mx[i]-a[i];
    if(u<=0)continue;
    u=log2(u+0.0)+1;
    ans=max(ans,u);

    }
    cout<<ans<<endl;
}
    return 0;
}
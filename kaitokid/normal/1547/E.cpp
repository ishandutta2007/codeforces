#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[300009],n,k,x[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)ans[i]=3000000000;
    for(int i=0;i<k;i++)cin>>x[i];
    for(int i=0;i<k;i++)
    {
       ll t;
       cin>>t;
        ans[x[i]]=t;
    }

    for(int i=2;i<=n;i++)ans[i]=min(ans[i-1]+1,ans[i]);
    for(int i=n-1;i>0;i--)ans[i]=min(ans[i+1]+1,ans[i]);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;

}
    return 0;
}
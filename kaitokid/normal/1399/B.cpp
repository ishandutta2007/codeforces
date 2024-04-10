#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[100009],b[100009];
int main()
{
ios::sync_with_stdio(0);
int n,t;
cin>>t;
while(t--)
{
    cin>>n;
    ll u=1e9,v=1e9,ans=0;
    for(int i=0;i<n;i++){cin>>a[i];u=min(u,a[i]);}
    for(int i=0;i<n;i++){cin>>b[i];v=min(v,b[i]);}
    for(int i=0;i<n;i++)
        ans+=max(a[i]-u,b[i]-v);

cout<<ans<<endl;
}
    return 0;
}
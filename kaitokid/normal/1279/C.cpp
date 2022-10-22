#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,x,ans,o;
ll a[200009],b[200009];
int main()
{
   ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    ans=0;
    o=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++){cin>>x;a[x]=i;}
    for(ll i=0;i<m;i++){cin>>x;
    if(a[x]<o){ans++;continue;}
    ans+=(a[x]-i)*2+1;o=a[x];}
    cout<<ans<<endl;

}
    return 0;
}
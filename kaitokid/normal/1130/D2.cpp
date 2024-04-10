#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,num[5004],ner[5004];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
ll x,y;
for(int i=0;i<m;i++)
{
    cin>>x>>y;
    num[x]++;
ll ff= (y-x+n)%n;
if(ner[x]==0||ner[x]>ff)ner[x]=ff;
}
for(int st=1;st<=n;st++)
{


ll ans=0;
for(int i=1;i<=n;i++)
    if(num[i]>0)ans=max(ans,(i-st+n)%n+(num[i]-1)*n+ner[i]);
cout<<ans<<" ";}
    return 0;
}
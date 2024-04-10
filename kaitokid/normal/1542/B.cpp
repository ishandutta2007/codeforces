#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
ll n,a,b;
cin>>n>>a>>b;
ll x=1;
bool ans=false;

while(x<=n)
{
    if(((n-x)%b)==0){ans=true ;break;}
    x*=a;
    if(a==1)break;
}
if(ans)cout<<"Yes\n";
else cout<<"No\n";
}
    return 0;
}
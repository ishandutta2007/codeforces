#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;

int main() {
ios::sync_with_stdio(0);
ll k,ans=10;
cin>>k;
while(k)
{
ans+=9;
ll x=ans,res=0;
while(x)
{
res+=x%10;
x/=10;}
if(res==10)k--;




}
cout<<ans;
 return 0; }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1e9 + 7;
ll v (ll a,ll b)
{
if(b==0)return 1;
if(b==1) return a;
if(b%2) return (a*v(a,b-1))%MOD;
ll res = v(a,b/2);

return (res*res)%MOD;


}
int main()
{
ios::sync_with_stdio(0);
ll n,m,k;
cin>>n>>m>>k;
if(k==-1&&n%2!=m%2){cout<<0;return 0;}
n--;
m--;

cout<<v(v(2,m),n);
return 0;}
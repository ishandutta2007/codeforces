#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll n ,m;
ll pw(int a,int b)
{

if(b==1)return a;
if(b%2==1)return (pw(a,b-1)*a);
ll k= pw(a,b/2);
return (k*k);



}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
if(n>36){cout<<m;return 0;}
ll p=pw(2,n);
cout<<m%p;
return 0;}
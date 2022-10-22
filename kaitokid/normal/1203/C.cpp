#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res, x,ans;
set<ll>st;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(ll i=0;i<n;i++){cin>>x;res=__gcd(x,res);}
for(ll i=1;i<1000009;i++)
if(res%i==0) {st.insert(i);st.insert(res/i);}
cout<<st.size();
return 0;}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;

ll bigMod (ll a, ll e)
 { ll d=a%e;
ll v=MOD%e;
ll ans=0;
while(d!=0){ans++;d=(d+v)%e;}
return ans;


} 

int main()
{
string s1,s2;
cin>>s1>>s2;
int i=1;
cout<<s1[0];
while(i<s1.size()&&int(s1[i])<int(s2[0])){cout<<s1[i];i++;}
cout<<s2[0];
return 0;}
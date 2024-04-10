#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;

int main()
{ios::sync_with_stdio(0);

int n,t,k,d;
cin>>n>>t>>k>>d;
int r= ceil(n/(k+0.0))-1;
if(t*r<=d){cout<<"NO";return 0;}
cout<<"YES";
return 0;}
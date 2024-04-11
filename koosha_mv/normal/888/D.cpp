#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans=1;int main(){cin>>n>>k; if(k>=2) ans+=(n*(n-1))/2; if(k>=3) ans+=(n*(n-1)*(n-2))/3; if(k>=4) ans+=(n*(n-1)*(n-2)*(n-3))/8*3; cout<<ans; }
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    ll n,s;
   cin>>n>>s;
   if(s<2*n){cout<<"NO";return 0;}
   cout<<"YES\n";
   for(int i=0;i<n-1;i++)
   {
       cout<<2<<" ";
       s-=2;
   }
   cout<<s<<endl;
   cout<<1;
    return 0;
}
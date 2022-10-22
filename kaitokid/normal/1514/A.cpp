#include <bits/stdc++.h>

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
       int n;
       cin>>n;
       bool ans=false;
       for(int i=0;i<n;i++)
       {
           int x;
           cin>>x;
           int u=sqrt(x);
           if(u*u!=x)ans=true;
       }
      if(ans)cout<<"YES\n";
      else cout<<"NO\n";
   }
    return 0;
}
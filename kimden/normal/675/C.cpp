#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int n,a;
   ll sum=0;
   map<ll,int> mp;
   cin >> n;
   for(int i=0;i<n;i++){
      cin >> a;
      sum += a;
      mp[sum]++;
   }
   int mx = 0;
   for(auto m: mp){
      mx = max(mx,m.second);
   }
   cout << n - mx;
   return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int n,m,a;
   cin >> n >> m;
   vector<int> v;
   for(int i=0;i<m;i++){
      cin >> a;
      v.push_back(a);
   }
   sort(v.begin(),v.end());
   int ans=1e6;
   for(int i=0;i<=m-n;i++){
      ans = min(ans,v[i+n-1]-v[i]);
   }
   cout << ans;
}
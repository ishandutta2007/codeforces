#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int n,a,ans,cur;
   cin >> n;
   vector<int> v(n),u(n);
   for(int i=0;i<n;i++){
      cin >> a;
      v[i] = a;
   }
   u[0] = 0;
   ans = 1;
   cur = 1;
   for(int i=1;i<n;i++){
      u[i] = v[i]-v[i-1];
      if(u[i]>=0){
         cur++;
      }else{
         ans = max(ans,cur);
         cur = 1;
      }
   }
   ans = max(ans,cur);
   cout << ans;
   return 0;
}
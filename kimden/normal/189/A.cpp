#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int n,a,b,c,ans=0;
   cin >> n >> a >> b >> c;
   for(int i=0;i<=n/a;i++){
      for(int j=0;j<=n/b;j++){
         if(n-i*a-j*b>=0 && (n-i*a-j*b)%c==0){
            ans = max(ans,i+j+(n-i*a-j*b)/c);
         }
      }
   }
   cout << ans;
   return 0;
}
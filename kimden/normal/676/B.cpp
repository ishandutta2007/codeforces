#include <bits/stdc++.h>
using namespace std;
int main()
{
   double a[15][15]={};
   double c;
   int n,t;
   int ans=0;
   cin >> n >> t;
   a[0][0] = t;
   for(int i=0;i<n;i++){
      for(int j=0;j<=i;j++){
         if(a[i][j]>=1){
            ans++;
            c = a[i][j]-1;
            a[i+1][j] += c/2;
            a[i+1][j+1] += c/2;
         }
      }
   }
   cout << ans;
   return 0;
}
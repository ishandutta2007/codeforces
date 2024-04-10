#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main(){
   int a,b,c;
   int n,x,y,z,t,ans=0;
   long long q,w;
   cin >> x >> y >> z >> t >> n;
   for(int i=0;i<n;i++){
      cin >> a >> b >> c;
      q = a*1LL*x+b*1LL*y+c;
      w = a*1LL*z+b*1LL*t+c;
      //cout << q << "\t" << w << "\n";
      if((q<0 && w>0)||(q>0 && w<0)){
         ans++;
      }
   }
   cout << ans;
   return 0;
}
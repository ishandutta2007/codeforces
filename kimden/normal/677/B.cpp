#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000007

int main()
{
   int n,h,k,a,rem=0;
   long long t=0;
   cin >> n >> h >> k;
   for(int i=0;i<n;i++){
      cin >> a;
      if(rem+a<=h){
         rem+=a;
      }else{
         rem = a;
         t++;
      }
      t += rem/k;
      rem%=k;
   }
   if(rem>0){
      t++;
   }
   cout << t;
}
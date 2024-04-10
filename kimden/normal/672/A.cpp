#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000007

int main()
{
   int n;
   cin >> n;
   if(n<=9){
      cout << n;
      return 0;
   }
   n-=9;
   if(n<=180){
      switch(n%2){
      case 0:
         cout << (9+n/2)%10;
         break;
      case 1:
         cout << (10+n/2)/10;
         break;
      }
      return 0;
   }
   n-=180;
   if(n<=2700){
      switch(n%3){
      case 0:
         cout << (99+n/3)%10;
         break;
      case 2:
         cout << ((100+n/3)/10)%10;
         break;
      case 1:
         cout << (100+n/3)/100;
         break;
      }
      return 0;
   }
   cout << -1;
}
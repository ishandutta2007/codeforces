#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   int a=0;
   bool b = (n%4==0)&&(n%100!=0 || n%400==0);
   bool d = b;
   int c = a;
   do{
      n++;
      if(d){
         c++;
      }
      c++;
      d = (n%4==0)&&(n%100!=0 || n%400==0);
      c%=7;
   }while(c!=0 || d!=b);
   cout << n;
}
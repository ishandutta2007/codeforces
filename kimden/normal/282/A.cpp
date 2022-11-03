#include <bits/stdc++.h>
using namespace std;
int main()
{
   int a=0,n;
   string s;
   cin >> n;
   for(int i=0;i<n;i++){
      cin >> s;
      switch(s[1]){
      case '+': 
         a++;
         break;
      case '-': 
         a--;
         break;
      }
   }
   cout << a;
   return 0;
}